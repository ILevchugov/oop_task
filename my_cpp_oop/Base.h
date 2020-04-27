#pragma once
#include <iostream>

class Printable {
public:
	virtual std::string print() const = 0;
};

class Named : public Printable {
public:
	Named(const std::string &name) : m_name(name) { }
	
	std::string getName() const {
		return m_name;
	}

	std::string print() const override {
		return m_name;
	}
private:
	std::string m_name;
};