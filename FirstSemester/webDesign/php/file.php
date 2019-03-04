<?php

$op = $_POST['option'];
$text = $_POST['text'];

switch($op){
    case 1:{
        $file = fopen('test.txt','w') or die('Not found');
        echo "<pre>File Created</pre>";
        break;
    }

    case 2:{
        $fileN = "test.txt";
        $file = fopen($fileN,'w') or die("Not Found");
        fwrite($file,$text);
        echo "<pre>Done Succefully</pre>";
        break;
    }

    case 3:{
        $fileN = "test.txt";
        $file = fopen($fileN,'r') or die("Not Found");
        $fileSize = filesize($fileN);
        echo fread($file,$fileSize);
        break;
    }

    case 4:{
        $fileN = "test.txt";
        $file = fopen($fileN,'r') or die("Not Found");
        fclose($file);
        break;
    }
    case 5:{
        $fileN = "test.txt";
        $file = fopen($fileN,'a') or die("Not Found");
        fwrite($file,$text);
        echo "<pre>Data Appended</pre>";
        break;
    }

}