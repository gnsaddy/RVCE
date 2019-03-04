<?php

    $op = $_POST['color'];
    $un = $_POST['text'];
    echo $un;

    switch($op){
        case 'red':
            $change = "rgb(225,0,0)";
            break;
        case 'green':
            $change = "rgb(0,225,0)";
            break;
        case 'blue':
            $change = "rgb(0,0,225)";
            break;
        default:
        $change = "rgb(225,225,225)";
    }


    ?>
    <html>
    <body style="background:<?php echo $change; ?>">
</body>
</html>