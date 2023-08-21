<?php
    session_start();
    include_once('login_header.php');
    require_once('Config.inc.php');
    $conn_str = DB_SYS.':host='.DB_HOST.';dbname='.DB_NAME;
    try {
        $pdo = new PDO($conn_str,DB_USER,DB_PASS);
        $username = "";
        $password = "";
        if(isset($_POST['username'])){
            $username = $_POST['username'];
        }
        if(isset($_POST['password'])){
            $password = $_POST['password']; 
        }
        $sql = "SELECT * FROM accounts WHERE username='$username'";
        $users = $pdo->query($sql);
        if ($user = $users->fetch()) {
            if(($user['username']==$username)){
                echo "<h1>Already account exist with this username please use another!</h1>";
            }
        }else{ 
            $sql = "INSERT INTO accounts(username,password) VALUES(:username,:password)";
            $stmt = $pdo->prepare($sql);
            $stmt->bindParam(':username',$username,PDO::PARAM_STR);
            $stmt->bindParam(':password',$password,PDO::PARAM_STR);
            $stmt->execute();
            $_sql = "SELECT * FROM accounts WHERE username=:username AND password=:password";
            $_stmt = $pdo->prepare($_sql);
            $_stmt->bindParam(':username',$username,PDO::PARAM_STR);
            $_stmt->bindParam(':password',$password,PDO::PARAM_STR);
            $_stmt->execute();
            if ($_user = $_stmt->fetch()) {
                if(($_user['username']==$username) && ($_user['password']==$password)){
                    $_SESSION['ID'] = $_user['ID'];
                    $_SESSION['username'] = $username;
                    header('Location: Add_Users.php',true,302);
                    die();
                }
                else{
                    header('Location: signup_page.php',true,302);
                    die();
                }
            }
            else{
                header('Location: signup_page.php',true,302);
                die();
            }             
        }       
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>New User</title>
</head>
<body>
</body>
</html>
<?php
    }catch (PDOException $e) {
        die('Server Error');
    }
?>