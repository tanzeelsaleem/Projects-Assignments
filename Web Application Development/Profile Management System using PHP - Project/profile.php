<?php
    session_start();
    if(isset($_SESSION['ID'])){
        include_once('Header_file.php');
        require_once('Config.inc.php');
        $conn_str = DB_SYS.':host='.DB_HOST.';dbname='.DB_NAME;
        function redirect (){
            header('Location: Show_Users.php',true,302);
            die();
        }
        try {
            $pdo = new PDO($conn_str,DB_USER,DB_PASS);
            if(isset($_SESSION['ID'])){
                $id = $_SESSION['ID'];
            }else{
                redirect();
            }
            $sql = 'SELECT * FROM users WHERE ID=:ID';
            $stmt = $pdo->prepare($sql);
            $stmt->bindValue(':ID',$id,PDO::PARAM_INT);
            $stmt->execute();
            if ($user = $stmt->fetch()) {
    ?><!DOCTYPE html>
    <html>
        <head>
            <title>Personal Home Page</title>
            <meta charset="utf-8">
            <meta name="viewport" content="width=device-width, initial-scale=1">
            <link href="bootstrap.min.css" rel="stylesheet">
            <link rel="stylesheet" href="style.css">
        </head>
        <body>
            <?php include_once('Header_file.php');?>
            <nav class="navbar navbar-expand-lg bg-dark navbar-dark" id="top">
            <div class="container-fluid">
                <a href="#" class="navbar-brand">Personal Homepage</a>
                    <button class="navbar-toggler allign-right" type="button" data-bs-toggle="collapse" data-bs-target="#nav">
                        <span class="navbar-toggler-icon"></span>
                    </button> 
                <div class="collapse navbar-collapse" id="nav">
                    <ul class="navbar-nav ms-auto hover">
                        <li class="nav-item"><a href="#a" class="nav-link">Contact Information</a></li>
                        <li class="nav-item"><a href="#c" class="nav-link">Profile</a></li>
                        <li class="nav-item"><a href="#d" class="nav-link">Objectives</a></li>
                        <li class="nav-item"><a href="#e" class="nav-link">Education</a></li>
                        <li class="nav-item"><a href="#f" class="nav-link">Experience</a></li>
                        <li class="nav-item"><a href="#g" class="nav-link">Awards and Honors</a></li>
                        <li class="nav-item"><a href="#h" class="nav-link">Skills</a></li>
                        <li class="nav-item"><a href="#i" class="nav-link">Language</a></li>
                        <li class="nav-item"><a href="#j" class="nav-link">Hobbies and Interests</a></li>
                        <li class="nav-item"><a href="#k" class="nav-link">References</a></li>
                    </ul>
                </div>
            </div>
        </nav>

        <div class="bg-dark text-light p-5 text-center text-sm-start">
            <div class="containter">
                <div class="d-sm-flex allign-items-center">
                    <div>
                        <img src="Profile.png" class="img-fluid w-50 col-md-2" alt="profile">
                    </div>
                    <div>
                        <h1 class="h1 container-fluid"><b><?php echo $user['fname'];?></b> <span class="text_color"><b><?php echo $user['lname']; ?></b></span></h1>
                        <h3>I am a student of <?php echo $user['department']; ?> in <span class="text_color"> <?php echo $user['uni']; ?></span></h3>
                        <h3>And i am <?php echo $user['age']; ?> years old.</h3>
                    </div>
                </div>
            </div>
        </div>
        <br>
        <div>
            <div class="main px-5">
                <div>
                    <br>
                    <h2 id="a" class="bg-teal text-white shadow text-shadow">Contact Information:</h2>
                    <p><strong>Phone No#: </strong><?php echo $user['mobile'];?></p>
                    <p><strong>Email: </strong><?php echo $user['email'];?></p>
                    <p><strong>Address: </strong><?php echo $user['uni']; ?>, Department of <?php echo $user['department']; ?>.</p>
                </div>

                <div>
                    <h2 id="c" class="bg-teal text-white shadow text-shadow">Profile:</h2>
                    <p><?php echo $user['profile']; ?></p>
                </div>
                    
                <div>
                    <h2 id="d" class="bg-teal text-white shadow text-shadow">Objective:</h2>
                    <p><?php echo $user['objective']; ?></p>
                </div>
                    
                <div>
                    <h2 id="e" class="bg-teal text-white shadow text-shadow">Education:</h2>
                        <ol id="li_font">
                            <li id="li_font" ><strong><span>Matriculation</span></strong></li>
                                <details>
                                    <summary>Details about my Matriculation</summary>
                                    <table class="table table-dark table-hover p-sm-0 p-md-0 p-lg-0 p-xl-0 px-xxl-0">
                                        <caption><strong>Result Detials</strong></caption>
                                        <thead>
                                            <tr><th>Sr. No.</th><th>Name Of Subjects</th><th>Grades</th></tr>
                                        </thead>
                                        <tbody>
                                            <tr><td>1</td><td><?php echo $user['mats1']; ?></td><td><?php echo $user['mats1_g']; ?></td></tr>
                                            <tr><td>2</td><td><?php echo $user['mats2']; ?></td><td><?php echo $user['mats2_g']; ?></td></tr>
                                            <tr><td>3</td><td><?php echo $user['mats3']; ?></td><td><?php echo $user['mats3_g']; ?></td></tr>
                                        </tbody>
                                    </table>
                                </details>
                            <br>    
                            <li><strong><span>Intermediate</span></strong></li>
                                <details>
                                    <summary>Details about my Intermediate</summary>
                                    <table class="table table-dark table-hover">
                                        <caption><strong>Result Details</strong></caption>
                                        <thead>
                                            <tr><th>Sr. No.</th><th>Name Of Subjects</th><th>Grades</th></tr>
                                        </thead>
                                        <tbody>
                                            <tr><td>1</td><td><?php echo $user['inters1']; ?></td><td><?php echo $user['inters1_g']; ?></td></tr>
                                            <tr><td>2</td><td><?php echo $user['inters2']; ?></td><td><?php echo $user['inters2_g']; ?></td></tr>
                                            <tr><td>3</td><td><?php echo $user['inters3']; ?></td><td><?php echo $user['inters3_g']; ?></td></tr>
                                        </tbody>
                                    </table>
                                    </details>
                                <br>    
                                <li><strong><span>Bachelor in <?php echo $user['department']; ?></span></strong></li>
                                    <details>
                                    <summary>Details about my Bachelor</summary>
                                    <table class="table table-dark table-hover">
                                        <caption><strong>Subject Details</strong></caption>
                                        <thead>
                                            <tr><th>Sr. No.</th><th>Name Of Subjects</th><th>Grades/Continue</th></tr>
                                        </thead>
                                        <tbody>
                                            <tr><td>1</td><td><?php echo $user['bachs1']; ?></td><td><?php echo $user['bachs1_g']; ?></td></tr>
                                            <tr><td>2</td><td><?php echo $user['bachs2']; ?></td><td><?php echo $user['bachs2_g']; ?></td></tr>
                                            <tr><td>3</td><td><?php echo $user['bachs3']; ?></td><td><?php echo $user['bachs3_g']; ?></td></tr>
                                        </tbody>
                                    </table>
                                </details>
                            <br>
                        </ol>
                    </div>
                
                    <div>
                        <h2 id="f" class="bg-teal text-white shadow text-shadow">Experience:</h2>
                        <p><?php echo $user['experience']; ?></p>
                    </div>
                    
                    <div>
                        <h2 id="g" class="bg-teal text-white shadow text-shadow">Awards and Honors:</h2>
                        <p><?php echo $user['award']; ?></p>
                    </div>
                    
                    <div>
                        <h2 id="h" class="bg-teal text-white shadow text-shadow">Skills</h2>
                        <ol id="li_font">
                            <li><strong><span><?php echo $user['s1_name']; ?></span></strong></li>
                                <details>
                                <summary>Details</summary>
                                <p1 class="p1_font_size">I have Experience of <?php echo $user['s1_year']; ?>years. <?php echo $user['s1_desc']; ?></p1>
                                </details>
                            <br>    
                            <li><strong><span><?php echo $user['s2_name']; ?></span></strong></li>
                                <details>
                                <summary>Details</summary>
                                <p1 class="p1_font_size">I have Experience of <?php echo $user['s2_year']; ?>years. <?php echo $user['s2_desc']; ?></p1>
                                </details>
                            <br>
                            <li><strong><span><?php echo $user['s3_name']; ?></span></strong></li>
                                <details>
                                <summary>Details</summary>
                                <p1 class="p1_font_size">I have Experience of <?php echo $user['s3_year']; ?>years. <?php echo $user['s3_desc']; ?></p1>
                                </details>
                        </ol>
                    </div>
                
                    <div>
                        <h2 id="i" class="bg-teal text-white shadow text-shadow">Language:</h2>
                        <ol id="li_font">
                            <li><?php echo $user['lang1']; ?></li>
                            <li><?php echo $user['lang2']; ?></li>
                            <li><?php echo $user['lang3']; ?></li>
                        </ol>
                    </div>
                    
                    <div>
                        <h2 id="j" class="bg-teal text-white shadow text-shadow">Hobbies and Interests:</h2>
                        <ol id="li_font">
                            <li><?php echo $user['hobby1']; ?></li>
                            <li><?php echo $user['hobby2']; ?></li>
                            <li><?php echo $user['hobby3']; ?></li>
                        </ol>   
                    </div>
                    
                    <div>
                        <h2 id="k" class="bg-teal text-white shadow text-shadow">References:</h2>
                        <p><strong><span>Referenced by:</span></strong></p>
                        <p><strong>Name: </strong><?php echo $user['ref_name']; ?></p>
                        <p><strong>Contact: </strong><?php echo $user['ref_cont']; ?></p>
                        <p><strong>Address: </strong><?php echo $user['ref_add']; }?></p>
                    </div>
                </div>
                <br>
                <div class="px-5">
                    <a href="#top"><img src="arrow-up-circle-fill.svg" alt="button" width="50" height="50" style="float:right;"></a>
                </div>
                
            </div>
            <br>
        <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js" integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js" integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9T+ZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13" crossorigin="anonymous"></script>
    <?php
        }catch (PDOException $e) {
            die('Server Error');
            }
    }else{
        header('Location: index.php',true,302);
        die();
    }        
    ?>
    </body>
</html>