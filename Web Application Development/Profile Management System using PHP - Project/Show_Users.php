<?php
    session_start();
    include_once('Header_file.php');
    require_once('Config.inc.php');
    $conn_str = DB_SYS.':host='.DB_HOST.';dbname='.DB_NAME;
    try {
        $pdo = new PDO($conn_str,DB_USER,DB_PASS);
?><!DOCTYPE html>
<html>
    <head>
        <title>Users</title>
    </head>
    <body>
        <div class="container">
            <div class="Navigation">
            </div>
            <div class="Header">
                <br>
                <h1 class = "heading"><b>List of Users<b></h1>
            </div>
            
            <div class="Main">
                <ul>
            <?php
            $sql = 'SELECT * FROM users';
            $users = $pdo->query($sql);
            echo "<ol>";
            while ($user = $users->fetch()) {
                echo "<li class='l_font'><a href = 'User_Details.php?ID=".$user['ID']."' class='anch'><i>".$user['fname']." ".$user['lname']."</i></a></li>";
            }
            echo "</ol>";
    } catch (PDOException $e) {
             die('Server Error');
        }
?>
                </ul>
            </div>
            <div class=Footer">        
            </div>
        </div>
    </body>
</html>