<?php
    session_start();
    include_once('login_header.php');
    require_once('Config.inc.php');
    $conn_str = DB_SYS.':host='.DB_HOST.';dbname='.DB_NAME;
    try {
        $pdo = new PDO($conn_str,DB_USER,DB_PASS);
        $ID = 0;
        $username = "";
        $password = "";
        $rem="off";
        if(isset($_POST['username'])){
            $username = $_POST['username'];
            if(isset($_POST['password'])){
                $password = $_POST['password'];
                    $sql = "SELECT * FROM accounts WHERE username = :username AND password=:password";
                    $stmt = $pdo->prepare($sql);
                    $stmt->bindParam(':username',$username,PDO::PARAM_STR);
                    $stmt->bindParam(':password',$password,PDO::PARAM_STR);
                    $stmt->execute();
                    if ($user = $stmt->fetch()) {
                        if(($user['username']==$username) && ($user['password']==$password)){
                            $ID = $user['ID'];
                            //session
                            $_SESSION['ID'] = $ID;
                            $_SESSION['username'] = $user['username'];
                            $_sql = 'SELECT * FROM users WHERE ID=:ID';
                            $stmt = $pdo->prepare($_sql);
                            $stmt->bindValue(':ID',$ID,PDO::PARAM_INT);
                            $stmt->execute();
                            if ($_user = $stmt->fetch()) {
                                if($_user['ID'] == $ID){
                                    header('Location: profile.php',true,302);
                                    die();
                                } 
                            }
                            else {
                                header('Location: Add_Users.php',true,302);
                                die();
                            }
                    }
                    else {
                        echo '<h1>Account does not Exist!<h1>';
                    }
                }
                else{
                    echo '<h1>Account does not Exist!<h1>';
                }
            }
            else{
                echo '<h1>Account does not Exist!<h1>';
            }
            if(isset($_POST['remember'])){
                $rem = $_POST['remember'];
                if($_POST['remember'] == $rem){
                    $expiry = time()+60*60*24*7;
                    setcookie('username',$username,$expiry);
                }
            }  
        }
        else{
            echo '<h1>Account does not Exist!<h1>';
        }
    }catch (PDOException $e) {
        die('Server Error');
    }
?>