#pragma once
class Admin{
private:
	
public:
	Admin();
	~Admin();
};

class User : protected Admin {

public:
	User();
	~User();

};