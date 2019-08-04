<?php
include("./uploadStudent.php");
?>

<!DOCTYPE html>
<html lang="en">

<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta name="description" content="">
    <meta name="author" content="">

    <title> Upload | Student</title>

    <!-- Custom fonts for this template-->
    <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet" type="text/css">
    <!-- Page level plugin CSS-->
    <link href="vendor/datatables/dataTables.bootstrap4.css" rel="stylesheet">

    <!-- Custom styles for this template-->
    <link href="css/sb-admin.css" rel="stylesheet">

</head>

<body id="page-top">

<!--header start-->
<?php
include("./header.php");
?>

<div id="content-wrapper">
    <div class="container-fluid">
        <!-- Breadcrumbs-->
        <ol class="breadcrumb">
            <li class="breadcrumb-item">
                <a href="dashboard.php">Dashboard</a>
            </li>
            <li class="breadcrumb-item active">Upload Student Details</li>
        </ol>
        <!--     content add here -->
        <div class="container-fluid">
            <h3 align="center">Upload to Student database</h3><br />
            <form method="post" enctype="multipart/form-data">
                <label>Select Excel File</label>
                <input type="file" name="excel" />
                <br />
                <input type="submit" name="import" class="btn btn-info" value="Import" />
            </form>
            <br />
            <hr>
            <br />
        </div>

        <!-- DataTables Example -->
        <!--imported from uploadStudent.php -->
        <?php
//        include("./uploadStudent.php");

        $output .= "<tbody>";

        echo $output;

        $output .= "</tbody>";
        $output .= "</table>";
        ?>

    </div>
</div>
</div>
<!--ending of table started in uploadStudent.php -->
</div>

<!--end  /.container-fluid -->
<!---------------------------------------------------------------------------------------------------------->
<!--    Sticky Footer -->
<!--    <footer class="sticky-footer">-->
<!--        <div class="container my-auto">-->
<!--            <div class="copyright text-center my-auto">-->
<!--                <span>Copyright © crackTheCode 2019</span>-->
<!--            </div>-->
<!--        </div>-->
<!--    </footer>-->
</div>
<!-- /.content-wrapper -->
</div>
<!-- /#wrapper -->
<!-------------------------------------------------------------------------------------------------------->
<!-- Scroll to Top Button-->
<a class="scroll-to-top rounded" href="#page-top">
    <i class="fas fa-angle-up"></i>
</a>

<!-- Logout Modal-->
<div class="modal fade" id="logoutModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
    <div class="modal-dialog" role="document">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title" id="exampleModalLabel">Ready to Leave?</h5>
                <button class="close" type="button" data-dismiss="modal" aria-label="Close">
                    <span aria-hidden="true">×</span>
                </button>
            </div>
            <div class="modal-body">Select "Logout" below if you are ready to end your current session.</div>
            <div class="modal-footer">
                <button class="btn btn-secondary" type="button" data-dismiss="modal">Cancel</button>
                <a class="btn btn-primary" href="logout.php">Logout</a>
            </div>
        </div>
    </div>
</div>

<!-- Bootstrap core JavaScript-->
<script src="vendor/jquery/jquery.min.js"></script>
<script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>

<!-- Core plugin JavaScript-->
<script src="vendor/jquery-easing/jquery.easing.min.js"></script>

<!-- Page level plugin JavaScript-->
<script src="vendor/chart.js/Chart.min.js"></script>
<script src="vendor/datatables/jquery.dataTables.js"></script>
<script src="vendor/datatables/dataTables.bootstrap4.js"></script>

<!-- Custom scripts for all pages-->
<script src="js/sb-admin.min.js"></script>

<!-- Demo scripts for this page-->
<script src="js/demo/datatables-demo.js"></script>
<script src="js/demo/chart-area-demo.js"></script>


</body>

</html>