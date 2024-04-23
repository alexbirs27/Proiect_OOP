#pragma once

#include <iostream>
#include <string>
class Mancare
{
private:
	std::string nume;
	float pret;
	int gramaj;
	int kcal;
public:
	Mancare() = default;
	~Mancare() = default;
	std::string GetNume() const {
		return nume;
	}
	float GetPret() const {
		return pret;
	}
	int GetGramaj() const {
		return gramaj;
	}
	int GetKcal() const {
		return kcal;
	}
	void SetNume(const std::string& nume_)
	{
		nume = nume_;
	}
	void SetPret(const float& pret_)
	{
		pret = pret_;
	}
	void SetGramaj(const int& gramaj_)
	{
		gramaj = gramaj_;
	}
	void SetKcal(const int& kcal_)
	{
		kcal = kcal_;
	}
	friend std::istream& operator>>(std::istream& f, Mancare& mancare);
};