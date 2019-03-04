<?php

$un = $_POST['un'];
$pw = $_POST['pw'];

if($un == 'aditya' and $pw == 123){
    session_start();
    $_SESSION['sid'] = session_id();
    echo '<pre>'. $un .'</pre>';
    echo '<pre>'. "Logged Succefully" .'</pre>';

    echo '<pre> <a href="out.php"> logout </a></pre>';
}
else{
    echo '<br><pre>'."Invalid";
}
?>