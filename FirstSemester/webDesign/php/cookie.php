<?php
date_default_timezone_set('Asia/kolkata');
$months = 60*60*60*24+time();

setcookie('visit',date('g:i - m/d/y'),$months);

if(isset($_COOKIE['visit'])){
    $lv = $_COOKIE['visit'];
    echo "Last visit is : ". $lv;
}
else{
    echo "No last visit ";
}

session_start();

if(isset($_SESSION['view'])){
    $_SESSION['view'] = $_SESSION['view']+1;
}
else{
    $_SESSION['view'] = 1;
}

echo "<br>".$_SESSION['view'];

?>