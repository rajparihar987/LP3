// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract BankAccount {
    address public owner;
    uint public balance;

    constructor() {
        owner = msg.sender;
        balance = 0;
    }

    function deposit() public payable {
        require(msg.value > 0, "Amount value must be greater than zero");
        balance = balance + msg.value;
    }

    function withdraw(uint amount) public {
        require(msg.sender == owner, "Only owner can withdraw");
        require(amount > 0, "Invalid withdrawl amount");
        require(amount <= balance, "Insufficient balance");

        balance = balance - amount;
        (bool success, ) = payable(owner).call{value: amount}("");
        require(success, "Failed");

    }

    function showBalance() public view returns (uint) {
        return balance;
    }
}