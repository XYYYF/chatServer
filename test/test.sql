DROP TABLE IF EXISTS `User`;
CREATE TABLE `User` (
    `id` INT NOT NULL AUTO_INCREMENT,
    `name` VARCHAR(50) NOT NULL,
    `password` VARCHAR(50) NOT NULL,
    `state` ENUM('online','offline') DEFAULT 'offline',
    PRIMARY KEY(`id`),
    UNIQUE(`name`)
) ENGINE=InnoDB;

LOCK TABLES `User` WRITE;
INSERT INTO `User` VALUES (13,'zhang san','123456','online'),(15,'li si','666666','offline'),(16,'liu shuo','123456','offline'),(18,'wu yang','123456','offline'),(19,'pi pi','123456','offline'),(21,'gao yang','123456','offline');
UNLOCK TABLES;


drop table if exists `Friend`;
create table `Friend`(
    `userid` INT NOT NULL,
    `friendid` INT NOT NULL,
    PRIMARY KEY(`userid`,`friendid`)
)ENGINE=InnoDB;

LOCK TABLES Friend WRITE;
INSERT INTO Friend VALUES(13,15),(13,21),(21,13),(21,15);
UNLOCK TABLES;


drop table if exists `AllGroup`;
create table `AllGroup`(
    `id` INT AUTO_INCREMENT,
    `groupname` VARCHAR(50) NOT NULL,
    `groupdesc` VARCHAR(200) DEFAULT '',
    PRIMARY KEY(`id`),
    UNIQUE(`groupname`)
)ENGINE=InnoDB;

LOCK TABLES `AllGroup` WRITE;
INSERT INTO `AllGroup` VALUES(1,'C++ chat project','start develop a chat project');
UNLOCK TABLES;

drop table if exists `GroupUser`;
create table `GroupUser`(
    `groupid` INT NOT NULL,
    `userid` INT NOT NULL,
    `grouprole` ENUM('creator','normal') DEFAULT 'normal',
    PRIMARY KEY(`groupid`,`userid`)
)ENGINE=InnoDB;

LOCK TABLES `GroupUser` WRITE;
INSERT INTO `GroupUser` VALUES(1,13,'creator'),(1,21,'normal'),(1,19,'normal');
UNLOCK TABLES;


drop table if exists `OfflineMessage`;
CREATE TABLE `OfflineMessage`(
    `userid` INT NOT NULL,
    `message` VARCHAR(500) NOT NULL
)ENGINE=InnoDB DEFAULT CHARSET=latin1;

LOCK TABLES `OfflineMessage` WRITE;
INSERT INTO `OfflineMessage` VALUES (19,'{\"groupid\":1,\"id\":21,\"msg\":\"hello\",\"msgid\":10,\"name\":\"gao yang\",\"time\":\"2020-02-22 00:43:59\"}'),(19,'{\"groupid\":1,\"id\":21,\"msg\":\"helo!!!\",\"msgid\":10,\"name\":\"gao yang\",\"time\":\"2020-02-22 22:43:21\"}'),(19,'{\"groupid\":1,\"id\":13,\"msg\":\"hahahahaha\",\"msgid\":10,\"name\":\"zhang san\",\"time\":\"2020-02-22 22:59:56\"}'),(19,'{\"groupid\":1,\"id\":13,\"msg\":\"hahahahaha\",\"msgid\":10,\"name\":\"zhang san\",\"time\":\"2020-02-23 17:59:26\"}'),(19,'{\"groupid\":1,\"id\":21,\"msg\":\"wowowowowow\",\"msgid\":10,\"name\":\"gao yang\",\"time\":\"2020-02-23 17:59:34\"}');
UNLOCK TABLES;