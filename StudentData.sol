// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract StudentData {
    struct Student {
        uint rollNo;
        string name;
        uint age;
        string course;
    }

    Student[] public students;

    fucntion addStudent(uint _rollNo, string memory _name, uint _age, string memory _course) public {
        students.push(
            Student(_rollNo,_name,_age,_course)
        );
    }

    function getStudent(uint index) public view returns(uint,string memory, uint,string memory) {
        require(index < students.length, "Invalid student index");

        Student memory s = students[index];
        return (s.rollNo, s.name, s.age, s.course);
    }

    function getStudentCount() public view returns(uint) {
        return student.length;
    }

    fallback() external payable {

    }

    recieve() external payable {

    }
}