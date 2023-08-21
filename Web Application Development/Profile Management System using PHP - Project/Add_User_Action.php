<?php
    session_start();
    include_once('Header_file.php');
    require_once('Config.inc.php');
    $conn_str = DB_SYS.':host='.DB_HOST.';dbname='.DB_NAME;
    function redierect (){
        header('Location: Show_Users.php',true,302);
        die();
    }
    try {
        $pdo = new PDO($conn_str,DB_USER,DB_PASS);
        $ID = 0;
        if(isset($_SESSION['ID'])){
            $ID = $_SESSION['ID'];
        }
        else{
            redierect();
        }
        $fname = "";
        $lname = "";
        $age = "";
        $mb_no = "";
        $email = "";
        $department = "";
        $uni = "";
        $mats1 = "";
        $mats1_g = "";
        $mats2 = "";
        $mats2_g = "";
        $mats3 = "";
        $mats3_g = "";
        $inters1 = "";
        $inters1_g = "";
        $inters2 = "";
        $inters2_g = "";
        $inters3 = "";
        $inters3_g = "";
        $bachs1 = "";
        $bachs1_g = "";
        $bachs2 = "";
        $bachs2_g = "";
        $bachs3 = "";
        $bachs3_g = "";
        $experience = "";
        $award = "";
        $s1_name = "";
        $s1_year = "";
        $s1_desc = "";
        $s2_name = "";
        $s2_year = "";
        $s2_desc = "";
        $s3_name = "";
        $s3_year = "";
        $s3_desc = "";
        $profile = "";
        $objective = "";
        $lang1 = "";
        $lang2 = "";
        $lang3 = "";
        $hobby1 = "";
        $hobby2 = "";
        $hobby3 = "";
        $ref_name = "";
        $ref_cont = "";
        $ref_add = "";
        if (isset($_POST['fname'])){
            $fname = $_POST['fname'];
        }else{
            redierect();
        }
        if (isset($_POST['lname'])){
            $lname = $_POST['lname'];
        }else{
            redierect();
        }
        if (isset($_POST['age'])){
            $age = $_POST['age'];
        }else{
            redierect();
        }
        if (isset($_POST['mb_no'])){
            $mb_no = $_POST['mb_no'];
        }else{
            redierect();
        }
        if (isset($_POST['email'])){
            $email = $_POST['email'];
        }else{
            redierect();
        }
        if (isset($_POST['dname'])){
            $department = $_POST['dname'];
        }else{
            redierect();
        }
        if (isset($_POST['uni'])){
            $uni = $_POST['uni'];
        }else{
            redierect();
        }
        if (isset($_POST['mats1'])){
            $mats1 = $_POST['mats1'];
        }else{
            redierect();
        }
        if (isset($_POST['mats2'])){
            $mats2 = $_POST['mats2'];
        }else{
            redierect();
        }
        if (isset($_POST['mats3'])){
            $mats3 = $_POST['mats3'];
        }else{
            redierect();
        }
        if (isset($_POST['mats1_g'])){
            $mats1_g = $_POST['mats1_g'];
        }else{
            redierect();
        }
        if (isset($_POST['mats2_g'])){
            $mats2_g = $_POST['mats2_g'];
        }else{
            redierect();
        }
        if (isset($_POST['mats3_g'])){
            $mats3_g = $_POST['mats3_g'];
        }else{
            redierect();
        }
        if (isset($_POST['inters1'])){
            $inters1 = $_POST['inters1'];
        }else{
            redierect();
        }
        if (isset($_POST['inters2'])){
            $inters2 = $_POST['inters2'];
        }else{
            redierect();
        }
        if (isset($_POST['inters3'])){
            $inters3 = $_POST['inters3'];
        }else{
            redierect();
        }
        if (isset($_POST['inters1_g'])){
            $inters1_g = $_POST['inters1_g'];
        }else{
            redierect();
        }
        if (isset($_POST['inters2_g'])){
            $inters2_g = $_POST['inters2_g'];
        }else{
            redierect();
        }
        if (isset($_POST['inters3_g'])){
            $inters3_g = $_POST['inters3_g'];
        }else{
            redierect();
        }
        if (isset($_POST['bachs1'])){
            $bachs1 = $_POST['bachs1'];
        }else{
            redierect();
        }
        if (isset($_POST['bachs2'])){
            $bachs2 = $_POST['bachs2'];
        }else{
            redierect();
        }
        if (isset($_POST['bachs3'])){
            $bachs3 = $_POST['bachs3'];
        }else{
            redierect();
        }
        if (isset($_POST['bachs1_g'])){
            $bachs1_g = $_POST['bachs1_g'];
        }else{
            redierect();
        }
        if (isset($_POST['bachs2_g'])){
            $bachs2_g = $_POST['bachs2_g'];
        }else{
            redierect();
        }
        if (isset($_POST['bachs3_g'])){
            $bachs3_g = $_POST['bachs3_g'];
        }else{
            redierect();
        }
        if (isset($_POST['exp'])){
            $experience = $_POST['exp'];
        }else{
            redierect();
        }
        if (isset($_POST['award'])){
            $award = $_POST['award'];
        }else{
            redierect();
        }
        if (isset($_POST['s1_name'])){
            $s1_name = $_POST['s1_name'];
        }else{
            redierect();
        }
        if (isset($_POST['s1_year'])){
            $s1_year = $_POST['s1_year'];
        }else{
            redierect();
        }
        if (isset($_POST['s1_desc'])){
            $s1_desc = $_POST['s1_desc'];
        }else{
            redierect();
        }
        if (isset($_POST['s2_name'])){
            $s2_name = $_POST['s2_name'];
        }else{
            redierect();
        }
        if (isset($_POST['s2_year'])){
            $s2_year = $_POST['s2_year'];
        }else{
            redierect();
        }
        if (isset($_POST['s2_desc'])){
            $s2_desc = $_POST['s2_desc'];
        }else{
            redierect();
        }
        if (isset($_POST['s3_name'])){
            $s3_name = $_POST['s3_name'];
        }else{
            redierect();
        }
        if (isset($_POST['s3_year'])){
            $s3_year = $_POST['s3_year'];
        }else{
            redierect();
        }
        if (isset($_POST['s3_desc'])){
            $s3_desc = $_POST['s3_desc'];
        }else{
            redierect();
        }
        if (isset($_POST['profile'])){
            $profile = $_POST['profile'];
        }else{
            redierect();
        }
        if (isset($_POST['objective'])){
            $objective = $_POST['objective'];
        }else{
            redierect();
        }
        if (isset($_POST['lang1'])){
            $lang1 = $_POST['lang1'];
        }else{
            redierect();
        }
        if (isset($_POST['lang2'])){
            $lang2 = $_POST['lang2'];
        }else{
            redierect();
        }
        if (isset($_POST['lang3'])){
            $lang3 = $_POST['lang3'];
        }else{
            redierect();
        }
        if (isset($_POST['hobby1'])){
            $hobby1 = $_POST['hobby1'];
        }else{
            redierect();
        }
        if (isset($_POST['hobby2'])){
            $hobby2 = $_POST['hobby2'];
        }else{
            redierect();
        }
        if (isset($_POST['hobby3'])){
            $hobby3 = $_POST['hobby3'];
        }else{
            redierect();
        }
        if (isset($_POST['ref_name'])){
            $ref_name = $_POST['ref_name'];
        }else{
            redierect();
        }
        if (isset($_POST['ref_cont'])){
            $ref_cont = $_POST['ref_cont'];
        }else{
            redierect();
        }
        if (isset($_POST['ref_add'])){
            $ref_add = $_POST['ref_add'];
        }else{
            redierect();
        }
        $sql = "INSERT INTO users(ID,fname,lname,age,mobile,email,department,uni,mats1,mats2,mats3,mats1_g,mats2_g,mats3_g,inters1,inters2,inters3,inters1_g,inters2_g,inters3_g,bachs1,bachs2,bachs3,bachs1_g,bachs2_g,bachs3_g,experience,award,s1_name,s1_year,s1_desc,s2_name,s2_year,s2_desc,s3_name,s3_year,s3_desc,profile,objective,lang1,lang2,lang3,hobby1,hobby2,hobby3,ref_name,ref_cont,ref_add) 
                            VALUES(:ID,:fname,:lname,:age,:mobile,:email,:department,:uni,:mats1,:mats2,:mats3,:mats1_g,:mats2_g,:mats3_g,:inters1,:inters2,:inters3,:inters1_g,:inters2_g,:inters3_g,:bachs1,:bachs2,:bachs3,:bachs1_g,:bachs2_g,:bachs3_g,:experience,:award,:s1_name,:s1_year,:s1_desc,:s2_name,:s2_year,:s2_desc,:s3_name,:s3_year,:s3_desc,:profile,:objective,:lang1,:lang2,:lang3,:hobby1,:hobby2,:hobby3,:ref_name,:ref_cont,:ref_add)";
        $stmt = $pdo->prepare($sql);
        $stmt->bindParam(':ID',$ID,PDO::PARAM_INT);
        $stmt->bindParam(':fname',$fname,PDO::PARAM_STR);
        $stmt->bindParam(':lname',$lname,PDO::PARAM_STR);
        $stmt->bindParam(':age',$age,PDO::PARAM_STR);
        $stmt->bindParam(':mobile',$mb_no,PDO::PARAM_STR);
        $stmt->bindParam(':email',$email,PDO::PARAM_STR);
        $stmt->bindParam(':department',$department,PDO::PARAM_STR);
        $stmt->bindParam(':uni',$uni,PDO::PARAM_STR);
        $stmt->bindParam(':mats1',$mats1,PDO::PARAM_STR);
        $stmt->bindParam(':mats2',$mats2,PDO::PARAM_STR);
        $stmt->bindParam(':mats3',$mats3,PDO::PARAM_STR);
        $stmt->bindParam(':mats1_g',$mats1_g,PDO::PARAM_STR);
        $stmt->bindParam(':mats2_g',$mats2_g,PDO::PARAM_STR);
        $stmt->bindParam(':mats3_g',$mats3_g,PDO::PARAM_STR);
        $stmt->bindParam(':inters1',$inters1,PDO::PARAM_STR);
        $stmt->bindParam(':inters2',$inters2,PDO::PARAM_STR);
        $stmt->bindParam(':inters3',$inters3,PDO::PARAM_STR);
        $stmt->bindParam(':inters1_g',$inters1_g,PDO::PARAM_STR);
        $stmt->bindParam(':inters2_g',$inters2_g,PDO::PARAM_STR);
        $stmt->bindParam(':inters3_g',$inters3_g,PDO::PARAM_STR);
        $stmt->bindParam(':bachs1',$bachs1,PDO::PARAM_STR);
        $stmt->bindParam(':bachs2',$bachs2,PDO::PARAM_STR);
        $stmt->bindParam(':bachs3',$bachs3,PDO::PARAM_STR);
        $stmt->bindParam(':bachs1_g',$bachs1_g,PDO::PARAM_STR);
        $stmt->bindParam(':bachs2_g',$bachs2_g,PDO::PARAM_STR);
        $stmt->bindParam(':bachs3_g',$bachs3_g,PDO::PARAM_STR);
        $stmt->bindParam(':experience',$experience,PDO::PARAM_STR);
        $stmt->bindParam(':award',$award,PDO::PARAM_STR);
        $stmt->bindParam(':s1_name',$s1_name,PDO::PARAM_STR);
        $stmt->bindParam(':s1_year',$s1_year,PDO::PARAM_STR);
        $stmt->bindParam(':s1_desc',$s1_desc,PDO::PARAM_STR);
        $stmt->bindParam(':s2_name',$s2_name,PDO::PARAM_STR);
        $stmt->bindParam(':s2_year',$s2_year,PDO::PARAM_STR);
        $stmt->bindParam(':s2_desc',$s2_desc,PDO::PARAM_STR);
        $stmt->bindParam(':s3_name',$s3_name,PDO::PARAM_STR);
        $stmt->bindParam(':s3_year',$s3_year,PDO::PARAM_STR);
        $stmt->bindParam(':s3_desc',$s3_desc,PDO::PARAM_STR);
        $stmt->bindParam(':profile',$profile,PDO::PARAM_STR);
        $stmt->bindParam(':objective',$objective,PDO::PARAM_STR);
        $stmt->bindParam(':lang1',$lang1,PDO::PARAM_STR);
        $stmt->bindParam(':lang2',$lang2,PDO::PARAM_STR);
        $stmt->bindParam(':lang3',$lang3,PDO::PARAM_STR);
        $stmt->bindParam(':hobby1',$hobby1,PDO::PARAM_STR);
        $stmt->bindParam(':hobby2',$hobby2,PDO::PARAM_STR);
        $stmt->bindParam(':hobby3',$hobby3,PDO::PARAM_STR);
        $stmt->bindParam(':ref_name',$ref_name,PDO::PARAM_STR);
        $stmt->bindParam(':ref_cont',$ref_cont,PDO::PARAM_STR);
        $stmt->bindParam(':ref_add',$ref_add,PDO::PARAM_STR);
        $stmt->execute();
?><!DOCTYPE html>
<html>
    <head>
        <title>Add New Users</title>
    </head>
    <body>
        <h1>User Added!</h1>    
<?php
    } catch (PDOException $e) {
       die('Server Error');
    }
?>
    </body>
</html>