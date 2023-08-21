<?php
    session_start();
    if(isset($_SESSION['ID'])){
        session_unset();
        session_destroy();
        header('Location: index.php',true,302);
        die();
    }
    else{
        header('Location: index.php',true,302);
        die();
    }
?>