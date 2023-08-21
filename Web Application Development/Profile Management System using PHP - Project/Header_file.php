<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link href="bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="header.css">
</head>
<body>
    <nav class="navbar navbar-expand-lg bg-dark navbar-dark" id="top">
        <div class="container-fluid">
            <a href="#" class="navbar-brand"><b>User:</b>
            <?php if(isset($_SESSION['username'])){
                        echo "@".$_SESSION['username'];
                    }
                    else{
                        echo "Guest";
                    }?></a>
                <button class="navbar-toggler allign-right" type="button" data-bs-toggle="collapse" data-bs-target="#nav">
                    <span class="navbar-toggler-icon"></span>
                </button> 
            <div class="collapse navbar-collapse" id="nav">
                <ul class="navbar-nav ms-auto hover">
                    <li class="nav-item"><a href="profile.php" class="nav-link"><b>Profile</b></a></li>
                    <li class="nav-item"><a href="update_profile.php" class="nav-link"><b>Update Profile</b></a></li>
                    <li class="nav-item"><a href="Show_Users.php" class="nav-link"><b>Users List</b></a></li>
                    <li class="nav-item"><a href="logout.php" class="nav-link"><b>Logout</b></a></li>
                </ul>
            </div>
        </div>
    </nav>
</body>
</html>