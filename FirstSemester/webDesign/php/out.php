<?php

echo "Logout succefully ";
session_start();
session_destroy();

echo '<br><pre><a href="logSession.html">Login</a></pre>';
?>