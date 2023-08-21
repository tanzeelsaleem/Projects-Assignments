<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <link rel="stylesheet" href="signup_page.css">
</head>
<body>
    <?php include_once('signup_header.php'); ?>
    <div class="signup">
        <h1><b>Sign Up</b></h1>
        <form action="signup_action.php" method="post">
            <table>
                <tr>
                    <td><b><label for="username">Enter UserName</label></b></td>
                </tr>
                <tr>
                    <td><input type="text" name="username" id="username"><p class="message1">&emsp; Note: Symbols are not allowed in the Name! & length must be greater than 5 & smaller than 12</p></td>
                </tr>
                <tr>
                    <td><b><label for="password">Enter Password: </label><b></td>
                </tr>
                <tr>
                    <td><input type="password" name="password" id="password"><p class="message2">&emsp; Note: Password must be of 8 characters</p></td>
                </tr>
                <tr>
                    <td><b><label for="rpassword">Re-Enter Password: </label></b></td>
                </tr>
                <tr>
                    <td><input type="password" name="rpassword" id="rpassword"><p class="message3">&emsp; Note: Password must be of 8 characters</p></td>
                </tr>
                <tr>
                    <td><p class="message4">&ensp; Note: Password doesn't match.</p></td>
                </tr>
                <tr>
                    <td><b><input type="submit" value="Sign Up"></b></td>
                </tr>
            </table>
        </form>
    </div>
<script src="signup.js" lang="javascript"></script>
</body>
</html>