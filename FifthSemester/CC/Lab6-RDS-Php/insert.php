<?php $link = mysqli_connect("database-2.cr59crx7tx0d.ap-south-1.rds.amazonaws.com", "root", "root12345", "demo");
if ($link === false) {
    die("ERROR: Could not connect. " . mysqli_connect_error());
}
$first_name = mysqli_real_escape_string($link, $_REQUEST['first_name']);
$last_name = mysqli_real_escape_string($link, $_REQUEST['last_name']);
$email = mysqli_real_escape_string($link, $_REQUEST['email']);
$sql = "INSERT INTO persons (first_name, last_name, email) VALUES ('$first_name', '$last_name', '$email')";
if (mysqli_query($link, $sql)) {
    echo "Records added successfully.";
} else {
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>Add Record Form</title>
</head>

<body>
    <h1>Enter to insert data</h1>
    <form action="insert.php" method="post">
        <p> <label for="firstName">First Name:</label> <input type="text" name="first_name" id="firstName"> </p>
        <p> <label for="lastName">Last Name:</label> <input type="text" name="last_name" id="lastName"> </p>
        <p> <label for="emailAddress">Email Address:</label> <input type="text" name="email" id="emailAddress"> </p>
        <input type="submit" value="Submit">
    </form>
    <h1>Inserted Data's</h1>
    <?php $sql = "SELECT * FROM persons";
    $result = mysqli_query($link, $sql);
    if (mysqli_num_rows($result) > 0) {
        while ($row = mysqli_fetch_assoc($result)) {
            echo "id: " . $row["first_name"] . " - Name: " . $row["last_name"] . " " . $row["email"] . "<br>";
        }
    } else {
        echo "0 results";
    }
    ?>
</body>

</html>