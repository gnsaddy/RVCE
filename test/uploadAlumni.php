<?php
//error_reporting(0);

include("./include/db.php");
session_start();
$output = ''; //already existing in database
$invalidusn = '';
$invalidrecord = ''; //valid usn
$temp = '';
if(isset($_POST["import"]))
{
    $count=0;
    $ct=0;
    $ct1=0;
    $bool=true;
    $takeExplode= explode(".", $_FILES["excel"]["name"]);
    $extension = end($takeExplode); // For getting Extension of selected file
    $allowed_extension = array("xls", "xlsx", "csv"); //allowed extension
    if(in_array($extension, $allowed_extension)) //check selected file extension is present in allowed extension array
    {
        $file = $_FILES["excel"]["tmp_name"]; // getting temporary source of excel file
        include("./PHPExcel/Classes/PHPExcel/IOFactory.php"); // Add PHPExcel Library in this code
        $objPHPExcel = PHPExcel_IOFactory::load($file); // create object of PHPExcel library by using load() method and in load method define path of selected file
//      starting of table ended in studentToDb.php page
        $output .= "<div class=\"card mb-3\">";
        $output .= "<div class=\"card-header\"> <i class=\"fas fa-table\"></i>
                Error's in the uploaded excel data
            </div><div class=\"card-body\">
                <div class=\"table-responsive\">";
        $invalidusn .= "<div class=\"table-responsive\">";
        $invalidrecord .= "<div class=\"table-responsive\">";
        $output .= "<table class=\"table table-bordered\" id=\"dataTable\" width=\"100%\" cellspacing=\"0\">
                        <thead>
                        <tr>
                            <th>USN</th>
                            <th>Name</th>
                            <th>Start</th>
                            <th>End</th>
                            <th>Company</th>
                            <th>Contact</th>
                        </tr>
                        </thead>";
        foreach ($objPHPExcel->getWorksheetIterator() as $worksheet)
        {
            $highestRow = $worksheet->getHighestRow();
            for($row=2; $row<=$highestRow; $row++)
            {
//                $output .= "<tr>";
                $usn = mysqli_real_escape_string($con, $worksheet->getCellByColumnAndRow(0, $row)->getValue());
                $name = mysqli_real_escape_string($con, $worksheet->getCellByColumnAndRow(1, $row)->getValue());
                $syear = mysqli_real_escape_string($con, $worksheet->getCellByColumnAndRow(2, $row)->getValue());
                $eyear = mysqli_real_escape_string($con, $worksheet->getCellByColumnAndRow(3, $row)->getValue());
                $company = mysqli_real_escape_string($con, $worksheet->getCellByColumnAndRow(4, $row)->getValue());
                $contact = mysqli_real_escape_string($con, $worksheet->getCellByColumnAndRow(5, $row)->getValue());


                $sql2 = "select usn from alumni";

                $data = mysqli_query($con,$sql2);

                $total=0;
                $total=mysqli_num_rows($data);
                if($total!=0)
                {
                    $rows=0;
                    while($rows=mysqli_fetch_assoc($data))
                    {
                        if($rows['usn']==$usn) {
                            $count = $count + 1;
                            $temp=$usn;

                            $output .= '<tr><td>' . $usn . '</td>';
                            $output .= '<td>' . $name . '</td>';
                            $output .= '<td>' . $syear . '</td>';
                            $output .= '<td>' . $eyear . '</td>';
                            $output .= '<td>' . $company . '</td>';
                            $output .= '<td>' . $contact . '</td>';
                            $output .= '</tr>';
                        }
                    }
                }
                if(preg_match("/^[1][A-Z][A-Z][0-9][0-9][A-Z][A-Z][A-Z][0-9][0-9]$/",$usn)) {
                    $query = "INSERT INTO alumni(usn,name,start_batch,end_batch,company,contact) VALUES ('" . $usn . "', '" . $name . "', " . $syear . ", " . $eyear . ", '" . $company . "', " . $contact . ")";
                    $bool = mysqli_query($con, $query);
                }
                else
                {

                    $ct = $ct + 1; //counting invalid usn
                    if($temp!=$usn) {
                        $count = $count + 1;
                    }
                    $invalidusn .= '<tr><td>' . $usn . '</td></tr>';
                }
                if(!$bool)
                {
                    //$ct1 = $ct1 + 1;  //valid usn but invalid  or null fields
                    if($temp!=$usn) {
                        $count = $count + 1;
                    }
                    $invalidrecord .= '<tr><td>' . $usn . '</td></tr>';
                }

            }

            if($count>0)
            {
                echo " <script> alert('$count records are not inserted!, $ct usn are invalid!');
                </script>";
            }
            else
            {
                echo " <script> alert('Records are inserted!');
                </script>";
            }
        }
        $output .= '</table>';
        $invalidrecord .= '</table>';
        $invalidusn .= '</table>';
    }
    else
    {
        $output = '<label class="text-danger">Invalid File</label>'; //if non excel file then
    }
}
?>

