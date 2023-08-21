-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 05, 2022 at 05:35 PM
-- Server version: 10.4.22-MariaDB
-- PHP Version: 8.0.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `users`
--

-- --------------------------------------------------------

--
-- Table structure for table `accounts`
--

CREATE TABLE `accounts` (
  `ID` int(11) NOT NULL,
  `username` varchar(15) COLLATE utf8mb4_bin NOT NULL,
  `password` varchar(8) COLLATE utf8mb4_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `accounts`
--

INSERT INTO `accounts` (`ID`, `username`, `password`) VALUES
(1, 'tanzeel12', 'tanzeel2'),
(2, 'Imaad402', 'imaad123'),
(3, 'naqeebkhan', 'naqeeb12'),
(4, 'username', 'user1234');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `ID` int(11) NOT NULL,
  `fname` varchar(12) COLLATE utf8mb4_bin NOT NULL,
  `lname` varchar(12) COLLATE utf8mb4_bin NOT NULL,
  `age` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `mobile` varchar(11) COLLATE utf8mb4_bin NOT NULL,
  `email` varchar(30) COLLATE utf8mb4_bin NOT NULL,
  `department` varchar(30) COLLATE utf8mb4_bin NOT NULL,
  `uni` varchar(30) COLLATE utf8mb4_bin NOT NULL,
  `mats1` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `mats2` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `mats3` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `mats1_g` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `mats2_g` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `mats3_g` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `inters1` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `inters2` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `inters3` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `inters1_g` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `inters2_g` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `inters3_g` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `bachs1` varchar(15) COLLATE utf8mb4_bin NOT NULL,
  `bachs2` varchar(15) COLLATE utf8mb4_bin NOT NULL,
  `bachs3` varchar(15) COLLATE utf8mb4_bin NOT NULL,
  `bachs1_g` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `bachs2_g` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `bachs3_g` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `experience` varchar(100) COLLATE utf8mb4_bin NOT NULL,
  `award` varchar(100) COLLATE utf8mb4_bin NOT NULL,
  `s1_name` varchar(20) COLLATE utf8mb4_bin NOT NULL,
  `s1_year` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `s1_desc` varchar(40) COLLATE utf8mb4_bin NOT NULL,
  `s2_name` varchar(20) COLLATE utf8mb4_bin NOT NULL,
  `s2_year` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `s2_desc` varchar(40) COLLATE utf8mb4_bin NOT NULL,
  `s3_name` varchar(20) COLLATE utf8mb4_bin NOT NULL,
  `s3_year` varchar(2) COLLATE utf8mb4_bin NOT NULL,
  `s3_desc` varchar(40) COLLATE utf8mb4_bin NOT NULL,
  `profile` varchar(150) COLLATE utf8mb4_bin NOT NULL,
  `objective` varchar(150) COLLATE utf8mb4_bin NOT NULL,
  `lang1` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `lang2` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `lang3` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `hobby1` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `hobby2` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `hobby3` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `ref_name` varchar(20) COLLATE utf8mb4_bin NOT NULL,
  `ref_cont` varchar(11) COLLATE utf8mb4_bin NOT NULL,
  `ref_add` varchar(30) COLLATE utf8mb4_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`ID`, `fname`, `lname`, `age`, `mobile`, `email`, `department`, `uni`, `mats1`, `mats2`, `mats3`, `mats1_g`, `mats2_g`, `mats3_g`, `inters1`, `inters2`, `inters3`, `inters1_g`, `inters2_g`, `inters3_g`, `bachs1`, `bachs2`, `bachs3`, `bachs1_g`, `bachs2_g`, `bachs3_g`, `experience`, `award`, `s1_name`, `s1_year`, `s1_desc`, `s2_name`, `s2_year`, `s2_desc`, `s3_name`, `s3_year`, `s3_desc`, `profile`, `objective`, `lang1`, `lang2`, `lang3`, `hobby1`, `hobby2`, `hobby3`, `ref_name`, `ref_cont`, `ref_add`) VALUES
(1, 'Tanzeel', 'Saleem', '21', '03186258800', 'mtanzeelsaleem5@gmail.com', 'Computer', 'Quaid i Azam', 'Mathematic', 'Physics', 'Biology', 'A+', 'A+', 'A+', 'Mathematic', 'Physics', 'Chemistry', 'A+', 'A+', 'A+', 'PSP', 'OOP', 'DSA', 'B', 'A', 'C', 'I', 'I', 'Programming', '2', 'I', 'Adobe', '3', 'I', 'Office', '3', 'I', 'I', 'My', 'Saraiki', 'Urdu', 'English', 'Playing', 'Bedminton', 'Cricket', 'Dr', '03123456789', 'CS'),
(2, 'Imaad', 'Nadeem', '18', '03230530308', 'imaadkhan@gmail.com', 'Economics', 'Quaid i Azam', 'Chemistry', 'Physics', 'Mathematic', 'A', 'A', 'A+', 'Physics', 'Chemistry', 'Mathematic', 'A', 'B', 'C', 'Micro Economics', 'Intermediate Ec', 'Macro Economics', 'B', 'A', 'C', 'I have done internship of 6  months at a private company.', 'NA', 'Microsoft Office', '2', 'Good at using it.', 'Autocad', '1', 'Expert in it.', 'Economics', '3', 'Understand it at the deep level.', 'I am imaad nadeem from Drosh Chitral.', 'I want to be the best economist of our country.', 'English', 'Urdu', 'Khowar', 'PUBG', 'Book Readi', 'Football', 'Sir Amanat', '03456789123', 'Economics Department QAU'),
(3, 'Naqeeb Ulah', 'Yousafzai', '22', '03125676542', 'naqaeebullah@gmail.com', 'History', 'Quaid i Azam', 'Chemistry', 'Physics', 'Mathematic', 'A', 'A', 'A+', 'Physics', 'Chemistry', 'Mathematic', 'A', 'B', 'C', 'South Asia', 'World Civilizat', 'English', 'B+', 'B+', 'B', 'I have studied the history at a very deep level, and knows very well about it.', 'I was awarded scholarship.', 'Filmora', '1', 'Good at using it.', 'History', '5', 'Knows very well.', 'Microsoft Office', '1', 'Beginner level', 'I am Naqeeb ullah Yousafzai from Deer Apar.', 'I am trying to explore the history, as much i can.', 'Pashtoo', 'Urdu', 'English', 'Book Readi', 'Football', 'Cricket', 'Misbah Ummar', '03134578907', 'History Department QAU');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `accounts`
--
ALTER TABLE `accounts`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `accounts`
--
ALTER TABLE `accounts`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
