<?php
    if (isset($_COOKIE['username'])){
        header('Location: Show_Users.php',true,302);
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <link rel="stylesheet" href="login_page.css">
</head>
<body>
    <?php include_once('login_header.php'); ?>
    <div class="login">
        <h1><b>Login</b></h1>
        <form action="login_user.php" method="post">
        <table>
            <tr>
                <td><b><label for="username">UserName</label><b></td>
            </tr>
            <tr>
                <td><input type="text" name="username" id="username"><p class="message1">&emsp; Note: Symbols are not allowed in the Name! & length must be greater than 5 & smaller than 12</p></td>
            </tr>
            <tr>
                <td><b><label for="password">Password: </label></b></td>
            </tr>
            <tr>
                <td><input type="password" name="password" id="password"><p class="message2">&emsp; Note: Password must be of 8 characters</p></td>
            </tr>
            <tr>
                <td><input type="checkbox" name="remember" id="remember"><b><label for="remember">&ensp;Remember Me</label></b></td>
            </tr>
            <tr>
                <td><b><input type="submit" value="Login" id="login"></b></td>
            </tr>
        </table>
    </form>
    </div>  
<script src="login.js" lang="javascript"></script>
</body>
</html>