<?php
    session_start();
    if(isset($_SESSION['ID'])){
    include_once('adduser_header.php');
    require_once('Config.inc.php');
    $conn_str = DB_SYS.':host='.DB_HOST.';dbname='.DB_NAME;
    try {
        $pdo = new PDO($conn_str,DB_USER,DB_PASS);
?><!DOCTYPE html>
<html>
    <head>
        <title>Add New User</title>
        <link rel="stylesheet" href="form.css">
    </head>
    <body>
        <h2><b  class="size">Welcome! @<?php if(isset($_SESSION['username'])){echo $_SESSION['username'];}?><b></h2>
        <h1>New User Data</h1>
        <div>
            <form method="post" action="Add_User_Action.php">
                <fieldset>
                    <legend><b>Personal Info.</b></legend>
                    <table>
                        <tr>
                            <td><label for="name"><b>First Name: </b></label></td>
                            <td><input type="text" name="fname" id="fname" placeholder="First Name" required><p class="message1">Note: Symbols or Numbers not allowed in the Name!</p></td>
                            <td><label for="name"><b>Last Name: </b></label></td>
                            <td><input type="text" name="lname" id="lname"placeholder="Last Name" required><p class="message2">Note: Symbols or Numbers not allowed in the Name!</p></td>
                        </tr>
                        <tr>
                            <td><label for="age"><b>Age: </b></label></td>
                            <td><input type="text" name="age" id="age" placeholder="18" required><p class="message3">Note: Age must be greater than 18 and less than 50 Years!</p><br></td>
                            <td><label for="mob"><b>Mobile Number: </b></label></td>
                            <td><input type="text" name="mb_no" id="mob_no" placeholder="03XXXXXXXXX" required><p class="message4">Note: Phone Number Pattern must be 03xxxxxxxxxx</p></td>
                        </tr>
                        <tr>
                            <td><label for="email"><b>Email: </b></label></td>
                            <td><input type="text" name="email" id="email" placeholder="abc@xyz.com" required><p class="message5">Note: Email Pattern must be abc@example.com</p></td>
                        </tr>   
                    </table>  
                </fieldset>
                <fieldset>
                    <legend><b>Education</b></legend>
                    <table>
                        <tr>
                            <td><label for="dept"><b>Department: </b></label></td>
                            <td><input type="text" name="dname" id="depart"  placeholder="Dept. Name" required><p class="message6">Note: Symbols or Numbers not allowed in Depart. Name!</p></td>
                            <td><label for="uni"><b>University Name: </b></label></td>
                            <td><input type="text" name="uni" id="uni" placeholder="Uni. Name" required><p class="message7">Note: Symbols or Numbers not allowed in University Name!</p></td>
                        </tr>
                    </table>
                    <table>
                        <tr>
                            <td><label for="mat"><b>Matriculation: </b></label></td>
                        </tr>
                        <tr>
                            <td><label for="mats1" style="color:black;"><b>Subject 1: </b></label></td>
                            <td><input type="text" name="mats1" placeholder="1" required></td>
                            <td><label for="grade" style="color:black;"><b>Grade: </b></label></td>
                            <td><input type="text" name="mats1_g" id="mats1_g" placeholder="Grade" required><p class="message8">Note: Only Grades (A+, A-, A, B+, B-, B, C+, C-, C, D+, D-, D and F) are allowed!</p></td>
                        </tr>
                        <tr>
                            <td><label for="mats2" style="color:black;"><b>Subject 2: </b></label></td>
                            <td><input type="text" name="mats2" placeholder="2" required></td>
                            <td><label for="grade" style="color:black;"><b>Grade: </b></label></td>
                            <td><input type="text" name="mats2_g" id="mats2_g" placeholder="Grade" required><p class="message9">Note: Only Grades (A+, A-, A, B+, B-, B, C+, C-, C, D+, D-, D and F) are allowed!</p></td>
                        </tr>
                        <tr>
                            <td><label for="mats3" style="color:black;"><b>Subject 3: </b></label></td>
                            <td><input type="text" name="mats3" placeholder="3" required></td>
                            <td><label for="grade" style="color:black;"><b>Grade: </b></label></td>
                            <td><input type="text" name="mats3_g" id="mats3_g" placeholder="Grade" required><p class="message10">Note: Only Grades (A+, A-, A, B+, B-, B, C+, C-, C, D+, D-, D and F) are allowed!</p></td>
                        </tr>
                        <tr>
                            <td><label for="inter"><b>Intermediate: </b></label></td>
                        </tr>
                        <tr>
                            <td><label for="inters1" style="color:black;"><b>Subject 1: </b></label></td>
                            <td><input type="text" name="inters1" placeholder="1" required></td>
                            <td><label for="grade" style="color:black;"><b>Grade: </b></label></td>
                            <td><input type="text" name="inters1_g" id="inters1_g" placeholder="Grade" required><p class="message11">Note: Only Grades (A+, A-, A, B+, B-, B, C+, C-, C, D+, D-, D and F) are allowed!</p></td>
                        </tr>
                        <tr>
                            <td><label for="inters2" style="color:black;"><b>Subject 2: </b></label></td>
                            <td><input type="text" name="inters2" placeholder="2" required></td>
                            <td><label for="grade" style="color:black;"><b>Grade: </b></label></td>
                            <td><input type="text" name="inters2_g" id="inters2_g" placeholder="Grade" required><p class="message12">Note: Only Grades (A+, A-, A, B+, B-, B, C+, C-, C, D+, D-, D and F) are allowed!</p></td>
                        </tr>
                        <tr>
                            <td><label for="inters3" style="color:black;"><b>Subject 3: </b></label></td>
                            <td><input type="text" name="inters3" placeholder="3" required></td>
                            <td><label for="grade" style="color:black;"><b>Grade: </b></label></td>
                            <td><input type="text" name="inters3_g" id="inters3_g" placeholder="Grade" required><p class="message13">Note: Only Grades (A+, A-, A, B+, B-, B, C+, C-, C, D+, D-, D and F) are allowed!</p></td>
                        </tr>
                        <tr>
                            <td><label for="bach"><b>Bachelor: </b></label></td>
                        </tr>
                        <tr>
                            <td><label for="bachs1" style="color:black;"><b>Subject 1: </b></label></td>
                            <td><input type="text" name="bachs1" placeholder="1" required></td>
                            <td><label for="grade" style="color:black;"><b>Grade: </b></label></td>
                            <td><input type="text" name="bachs1_g" id="bachs1_g" placeholder="Grade/Continue" required><p class="message14">Note: Grades (A+, A-, A, B+, B-, B, C+, C-, C, D+, D-, D and F) and continue allowed!</p></td>
                        </tr>
                        <tr>
                            <td><label for="bachs2" style="color:black;"><b>Subject 2: </b></label></td>
                            <td><input type="text" name="bachs2" placeholder="2" required></td>
                            <td><label for="grade" style="color:black;"><b>Grade: </b></label></td>
                            <td><input type="text" name="bachs2_g" placeholder="Grade/Continue" required><p class="message15">Note: Grades (A+, A-, A, B+, B-, B, C+, C-, C, D+, D-, D and F) and continue allowed!</p></td>
                        </tr>
                        <tr>
                            <td><label for="bachs3" style="color:black;"><b>Subject 3: </b></label></td>
                            <td><input type="text" name="bachs3" placeholder="3" required></td>
                            <td><label for="grade" style="color:black;"><b>Grade: </b></label></td>
                            <td><input type="text" name="bachs3_g" placeholder="Grade/Continue" required><p class="message16">Note: Grades (A+, A-, A, B+, B-, B, C+, C-, C, D+, D-, D and F) and continue allowed!</p></td>
                        </tr>
                    </table>
                </fieldset>
                <fieldset>
                    <legend><b>Experience</b></legend>
                    <label for="exp"><b>Experience: </b></label>
                    <input type="text" name="exp" placeholder="Experiences" required><br>
                    <label for="award"><b>Awards & Honors: </b></label>
                    <input type="text" name="award" placeholder="Awards" required><br>
                    <label for="skills"><b>Skills: </b></label>
                    <table>
                        <tr>
                            <td><label for="skill1" style="color:black;"><b>1: </b></label></td>
                            <td><input type="text" name="s1_name" placeholder="Name" required></td><td><label for=""></label></td>
                            <td><input type="text" name="s1_year" id="skill1" placeholder="Year" required><p class="message17">Note: Year must be of one digit or two.</p></td><td><label for=""></label></td>
                            <td><input type="text" name="s1_desc" placeholder="Description" required></td>
                        </tr>
                        <tr>
                            <td><label for="skill2" style="color:black;"><b>2: </b></label></td>
                            <td><input type="text" name="s2_name" placeholder="Name" required></td><td><label for=""></label></td>
                            <td><input type="text" name="s2_year" id="skill2" placeholder="Year" required><p class="message18">Note: Year must be of one digit or two.</p></td><td><label for=""></label></td>
                            <td><input type="text" name="s2_desc" placeholder="Description" required></td>
                        </tr>
                        <tr>
                            <td><label for="skill3" style="color:black;"><b>3: </b></label></td>
                            <td><input type="text" name="s3_name" placeholder="Name" required></td><td><label for=""></label></td>
                            <td><input type="text" name="s3_year" id="skill3" placeholder="Year" required><p class="message19">Note: Year must be of one digit or two.</p></td><td><label for=""></label></td>
                            <td><input type="text" name="s3_desc" placeholder="Description" required></td>
                        </tr>
                    </table>
                </fieldset>
                <fieldset>
                    <legend><b>Profile</b></legend>
                    <label for="profile"><b>Profile: </b></label>
                    <input type="text" name="profile" placeholder="Profile Description" required><br>
                    <label for="objective"><b>Objective: </b></label>
                    <input type="text" name="objective" placeholder="Objective Description" required><br>
                    
                    <table>
                        <tr>
                            <label for="lang"><b>Languages: </b></label>
                        </tr>
                        <tr>
                            <td><label for="1" style="color:black;"><b>1: </b></label></td>
                            <td><input type="text" name="lang1" required></td>
                            <td><label for="2" style="color:black;"><b>2: </b></label></td>
                            <td><input type="text" name="lang2" required></td>
                            <td><label for="3" style="color:black;"><b>3: </b></label></td>
                            <td><input type="text" name="lang3" required></td>
                        </tr>
                    </table>
                    <table>
                        <tr>
                            <label for="hobbies"><b>Hobbies & Intersent: </b></label>
                        </tr>
                        <tr>
                            <td><label for="h1" style="color:black;"><b>1: </b></label></td>
                            <td><input type="text" name="hobby1" required></td>
                            <td><label for="h2" style="color:black;"><b>2: </b></label></td>
                            <td><input type="text" name="hobby2" required></td>
                            <td><label for="h3" style="color:black;"><b>3: </b></label></td>
                            <td><input type="text" name="hobby3" required></td>
                        </tr>
                    </table>
                </fieldset>
                <fieldset>
                    <legend><b>References</b></legend>
                    <table>
                        <tr>
                            <td><label for="ref" style="color:black;"><b>Refered By: </b></label></td>
                        </tr>
                        <tr>
                            <td><input type="text" name="ref_name" id="refname" placeholder="Name" required><p class="message20">Note: Symbols or Numbers not allowed in the Name!</p></td><td><label for=""></label></td>
                            <td><input type="text" name="ref_cont" id="refmob_no" placeholder="Contact" required><p class="message21">Note: Phone Number Pattern must be 03xxxxxxxxxx</p></td><td><label for=""></label></td>
                            <td><input type="text" name="ref_add" id="ref_add" placeholder="Address" required></td>
                        </tr>
                    </table>
                </fieldset>
                <input type="submit" required>
            </form>
        </div>       
    <?php
        } catch (PDOException $e) {
            die('Server Error');
        }
    }else{
        header('Location: index.php',true,302);
        die();
    }
    ?>
<script src="form.js" lang="javascript"></script>
</body>
</html>