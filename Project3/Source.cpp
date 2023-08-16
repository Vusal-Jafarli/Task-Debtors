#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Date
{
	size_t _day;
	size_t _month;
	size_t _year;
public:
	Date()
	{
		_day = 0;
		_month = 0;
		_year = 0;
	}
	Date(size_t day, size_t month, size_t year)
	{
		_day = day;
		_month = month;
		_year = year;
	}

	void set_day(size_t day)
	{
		if (day > 0 && day < 32)
		{
			_day = day;
		}
		else
			throw invalid_argument("Date day is invalid.");
	}
	void set_month(size_t month)
	{
		if (month > 0 && month < 13)
		{
			_month = month;
		}
		else
			throw invalid_argument("Date month is invalid.");
	}
	void set_year(size_t year)
	{
		if (year > 1900)
		{
			_year = year;
		}
		else
			throw invalid_argument("Date month is invalid.");
	}

	size_t get_day() { return _day; }
	size_t get_month() { return _month; }
	size_t get_year() { return _year; }

	friend ostream& operator<<(ostream& os, Date& date);
};
ostream& operator<<(ostream& os, Date& date)
{
	os << date._day << "." << date._month << "." << date._year;
	return os;
}

class Debtor
{
	const char* _fullname;
	const char* _email;
	const char* _phone;
	const char* _address;
	Date _birthday;
	float _debt;


public:
	Debtor(const char* fullname, Date birthDay, const char* phone, const char* email, const char* address, float debt)
	{
		set_fullname(fullname);
		set_phone(phone);
		set_email(email);
		set_address(address);
		set_debt(debt);
		set_birthday_date(birthDay);

	}
	void set_fullname(const char* name)
	{
		if (string(name).size() > 1)
		{
			_fullname = name;
		}
		else
			throw invalid_argument("Invalid fullname");

	}
	void set_email(const char* email)
	{
		if (string(email).size() >= 3)
		{
			_email = email;
		}
		else
			throw invalid_argument("Invalid email");

	}
	void set_phone(const char* phone)
	{
		if (string(phone).size() > 8)
		{
			_phone = phone;
		}
		else
			throw invalid_argument("Invalid phone");

	}
	void set_address(const char* address)
	{
		if (string(address).size() > 8)
		{
			_address = address;
		}
		else
			throw invalid_argument("Invalid address");

	}
	void set_debt(float debt)
	{
		if (debt >= 0)
		{
			_debt = debt;
		}
		else
			throw invalid_argument("Invalid debt");

	}
	void set_birthday_date(Date date)
	{
		_birthday = date;
	}


	const char* get_name() { return _fullname; }
	const char* get_email() { return _email; }
	const char* get_phone() { return _phone; }
	const char* get_address() { return _address; }
	int get_debt() { return _debt; }
	Date& get_birthday() { return _birthday; }

	friend ostream& operator<<(ostream& os, Debtor& debtor);
};
ostream& operator<<(ostream& os, Debtor& debtor)
{
	os << "FullName: " << debtor._fullname << endl
		<< "Email: " << debtor._email << endl
		<< "Phone: " << debtor._phone << endl
		<< "Address: " << debtor._address << endl
		<< "Birtday: " << debtor._birthday << endl
		<< "Debt: " << debtor._debt << endl;

	return os;


}



void print_name(Debtor& debtor)
{
	cout << "FullName: " << debtor.get_name() << endl
		<< "Birtday: " << debtor.get_birthday() << endl
		<< "Debt: " << debtor.get_debt() << endl << endl;
}
void print(Debtor& d1)
{
	cout << d1 << endl;
}
bool removeByEmail(Debtor& d1)
{

	const char* email_1 = new char[11] {"dayrep.com"};
	const char* email_2 = new char[10] {"rhyta.com"};

	if (d1.get_email()[string(d1.get_email()).length() - 10] != 'd' && d1.get_email()[string(d1.get_email()).length() - 9] != 'r')
		return true;

	if (d1.get_email()[string(d1.get_email()).length() - 10] == 'd')
	{
		for (size_t i = 0; i < 10; i++)
		{
			char email_1_check = d1.get_email()[string(d1.get_email()).length() - 10 + i];
			if (email_1[i] != email_1_check)
				return true;
		}
	}
	else if (d1.get_email()[string(d1.get_email()).length() - 9] == 'r')
	{
		for (size_t i = 0; i < 9; i++)
		{
			char email_2_check = d1.get_email()[string(d1.get_email()).length() - 9 + i];
			if (email_2[i] != email_2_check)
				return true;
		}
	}

	return false;
}
bool removeByAge(Debtor& d1)
{
	return (2023 - (d1.get_birthday().get_year()) >= 26 && 2023 - (d1.get_birthday().get_year()) >= 26);
}
bool removeByDebt(Debtor& d1)
{
	return (d1.get_debt() > 5000);
}
bool remove_age_number(Debtor& d1)
{
	int say = 0;
	if (string(d1.get_name()).length() > 18)
	{
		for (size_t i = 0; i < string(d1.get_phone()).length(); i++)
		{

			if (d1.get_phone()[i] == '7')
			{
				say++;
			}

		}
		return !(say >= 2);

	}
	else
		return true;

}
bool remove_winter(Debtor& d1)
{

	return !(d1.get_birthday().get_month() == 12 ||
		d1.get_birthday().get_month() == 1 ||
		d1.get_birthday().get_month() == 2);
}
bool phone_8_number(Debtor& d1)
{
	for (size_t i = 0; i < string(d1.get_phone()).length(); i++)
	{
		if (d1.get_phone()[i] == '8')
			return true;
	}
	return false;
}
bool eyni_herf(Debtor& d1)
{
	int counter;
	for (size_t i = 0; i < string(d1.get_name()).length(); i++)
	{
		counter = 0;
		for (size_t j = i; j < string(d1.get_name()).length(); j++)
		{
			if (d1.get_name()[i] == d1.get_name()[j])
				counter++;

			if (d1.get_name()[i] >= 65 && d1.get_name()[i] <= 90) {

				if (d1.get_name()[i] + 32 == d1.get_name()[j])
					counter++;
			}
			if (d1.get_name()[j] >= 65 && d1.get_name()[j] <= 90) {

				if (d1.get_name()[i] == d1.get_name()[j] + 32)
					counter++;
			}
		}
		if (counter >= 3)
			return false;
	}
	return true;
}
bool sort_alphabetic(Debtor& d1, Debtor& d2)
{
	return d1.get_name() < d2.get_name();
}
bool max_year(Debtor& d1, Debtor& d2)
{
	return d1.get_birthday().get_year() == d2.get_birthday().get_year();
}
bool max_debbbt(Debtor& d1, Debtor& d2)
{
	return d1.get_debt() == d2.get_debt();
}
//bool max_debt(Debtor& d1)
//{
//	return d1.get_debt();
//}
bool dunya_muharibesi_sort(Debtor& d1)
{
	return !(d1.get_birthday().get_year() >= 1941 && d1.get_birthday().get_year() <= 1945);
}

bool not_same_number(Debtor& d1)
{
	for (size_t i = 0; i < string(d1.get_phone()).length() - 1; i++)
	{
		for (size_t j = i + 1; j < string(d1.get_phone()).length(); j++)
		{

			if (d1.get_phone()[i] == d1.get_phone()[j] && d1.get_phone()[i] != '-') {
				return true;
			}
		}
	}
	cout << "Name: " << d1.get_name() << endl
		<< "Number: " << d1.get_phone() << endl
		<< "Debt: " << d1.get_debt() << endl;
	return false;
}
bool oz_ad_gunu_kredit(Debtor& d1)
{
	bool ischeck = true;
	int ay = d1.get_birthday().get_month();
	(ay < 8) ? ay = 8 - ay : ay = 12 - (ay - 8);

	float odenis = ay * 500;
	(odenis >= d1.get_debt()) ? ischeck = false : ischeck = true;
	return ischeck;
}
bool sort_ty_smile(Debtor& d1)
{
	char* smile = new char[6] {"smile"};
	const char* debtor_name;
	bool ischeck ;

	for (size_t j = 0; j < string(smile).length(); j++)
	{
		ischeck = false;
		for (size_t i = 0; i < string(d1.get_name()).length(); i++)
		{
			if (d1.get_name()[i] >= 65 && d1.get_name()[i] <= 90)
			{
				if (d1.get_name()[i] == smile[j] - 32)ischeck = true;
			}
			else
			{
				if (d1.get_name()[i] == smile[j])ischeck = true;
			}
		}
		if (ischeck == false)
		{
			delete smile;
			delete debtor_name;
			return true;
		}
	}
	delete smile;
	delete debtor_name;
	return false;
}
void main()
{
	static list<Debtor> debtors;

	debtors.push_back(Debtor("Shirley T. Qualls", Date(30, 3, 1932), "530-662-7732", "DonnaBMaynard@teleworm.us", "3565 Eagles Nest Drive Woodland, CA 95695", 2414));
	debtors.push_back(Debtor("Danielle W. Grier", Date(18, 10, 1978), "321-473-4178", "DanielleWGrier@rhyta.com", "1973 Stoneybrook Road Maitland, FL 32751", 3599));
	debtors.push_back(Debtor("Connie W. Lemire", Date(18, 6, 1963), "828-321-3751", "ConnieWLemire@rhyta.com", "2432 Hannah Street Andrews, NC 28901", 1219));
	debtors.push_back(Debtor("Coy K. Adams", Date(1, 3, 1976), "410-347-1307", "CoyKAdams@dayrep.com", "2411 Blue Spruce Lane Baltimore, MD 21202", 3784));
	debtors.push_back(Debtor("Bernice J. Miles", Date(1, 6, 1989), "912-307-6797", "BerniceJMiles@armyspy.com", "4971 Austin Avenue Savannah, GA 31401", 4060));
	debtors.push_back(Debtor("Bob L. Zambrano", Date(28, 2, 1998), "123-456-7890", "BobLZambrano@armyspy.com", "2031 Limer Street Augusta, GA 30901", 6628));
	debtors.push_back(Debtor("Adam D. Bartlett", Date(6, 5, 1950), "650-693-1758", "AdamDBartlett@rhyta.com", "2737 Rardin Drive San Jose, CA 95110", 5412));
	debtors.push_back(Debtor("Pablo M. Skinner", Date(26, 8, 1946), "630-391-2034", "PabloMSkinner@armyspy.com", "16 Fraggle Drive Hickory Hills, IL 60457", 11097));
	debtors.push_back(Debtor("Dorothy J. Brown", Date(9, 7, 1990), "270-456-3288", "DorothyJBrown@rhyta.com", "699 Harper Street Louisville, KY 40202", 7956));
	debtors.push_back(Debtor("Larry A. Miracle", Date(22, 5, 1998), "301-621-3318", "LarryAMiracle@jourrapide.com", "2940 Adams Avenue Columbia, MD 21044", 7151));
	debtors.push_back(Debtor("Donna B. Maynard", Date(26, 1, 1944), "520-297-0575", "DonnaBMaynard@teleworm.us", "4821 Elk Rd Little Tucson, AZ 85704", 2910));
	debtors.push_back(Debtor("Jessica J. Stoops", Date(22, 4, 1989), "360-366-8101", "JessicaJStoops@dayrep.com", "2527 Terra Street Custer, WA 98240", 11805));
	debtors.push_back(Debtor("Audry M. Styles", Date(7, 2, 1937), "978-773-4802", "AudryMStyles@jourrapide.com", "151 Christie Way Marlboro, MA 01752", 1001));
	debtors.push_back(Debtor("Violet R. Anguiano", Date(4, 11, 1958), "585-340-7888", "VioletRAnguiano@dayrep.com", "1460 Walt Nuzum Farm Road Rochester, NY 14620", 9128));
	debtors.push_back(Debtor("Charles P. Segundo", Date(21, 10, 1970), "415-367-3341", "CharlesPSegundo@dayrep.com", "1824 Roosevelt Street Fremont, CA 94539", 5648));
	debtors.push_back(Debtor("Paul H. Sturtz", Date(15, 9, 1944), "336-376-1732", "PaulHSturtz@dayrep.com", "759 Havanna Street Saxapahaw, NC 27340", 10437));
	debtors.push_back(Debtor("Doris B. King", Date(10, 10, 1978), "205-231-8973", "DorisBKing@rhyta.com", "3172 Bedford Street Birmingham, AL 35203", 7230));
	debtors.push_back(Debtor("Deanna J. Donofrioo", Date(16, 4, 1983), "952-842-7576", "DeannaJDonofrio@rhyta.com", "1972 Orchard Street Bloomington, MN 55437", 515));
	debtors.push_back(Debtor("Martin S. Malinowski", Date(17, 1, 1992), "765-599-3523", "MartinSMalinowski@dayrep.com", "3749 Capitol Avenue debtors.push_back(new Castle, IN 47362", 1816));
	debtors.push_back(Debtor("Melissa R. Arner", Date(24, 4, 1974), "530-508-7328", "MelissaRArner@armyspy.com", "922 Hill Croft Farm Road Sacramento, CA 95814", 5037));
	/*debtors.push_back(Debtor("Kelly G. Hoffman", Date("September 22, 1969"), "505-876-8935", "KellyGHoffman@armyspy.com", "4738 Chapmans Lane Grants, NM 87020", 7755));
	debtors.push_back(Debtor("Doyle B. Short", Date("June 15, 1986"), "989-221-4363", "DoyleBShort@teleworm.us", "124 Wood Street Saginaw, MI 48607", 11657));
	debtors.push_back(Debtor("Lorrie R. Gilmore", Date("December 23, 1960"), "724-306-7138", "LorrieRGilmore@teleworm.us", "74 Pine Street Pittsburgh, PA 15222", 9693));
	debtors.push_back(Debtor("Lionel A. Cook", Date("April 16, 1972"), "201-627-5962", "LionelACook@jourrapide.com", "29 Goldleaf Lane Red Bank, NJ 07701", 2712));
	debtors.push_back(Debtor("Charlene C. Burke", Date("January 18, 1990"), "484-334-9729", "CharleneCBurke@armyspy.com", "4686 Renwick Drive Philadelphia, PA 19108", 4016));
	debtors.push_back(Debtor("Tommy M. Patton", Date("June 30, 1981"), "774-571-6481", "TommyMPatton@rhyta.com", "748 Rockford Road Westborough, MA 01581", 349));
	debtors.push_back(Debtor("Kristin S. Bloomer", Date("June 16, 1944"), "443-652-0734", "KristinSBloomer@dayrep.com", "15 Hewes Avenue Towson, MD 21204", 9824));
	debtors.push_back(Debtor("Daniel K. James", Date("November 10, 1997"), "801-407-4693", "DanielKJames@rhyta.com", "3052 Walton Street Salt Lake City, UT 84104", 8215));
	debtors.push_back(Debtor("Paula D. Henry", Date("September 6, 1976"), "618-378-5307", "PaulaDHenry@rhyta.com", "3575 Eagle Street Norris City, IL 62869", 5766));
	debtors.push_back(Debtor("Donna C. Sandoval", Date("December 13, 1947"), "540-482-5463", "DonnaCSandoval@rhyta.com", "675 Jehovah Drive Martinsville, VA 24112", 8363));
	debtors.push_back(Debtor("Robert T. Taylor", Date("August 17, 1932"), "270-596-6442", "RobertTTaylor@armyspy.com", "2812 Rowes Lane Paducah, KY 42001", 7785));
	debtors.push_back(Debtor("Donna W. Alamo", Date("December 9, 1948"), "978-778-2533", "DonnaWAlamo@teleworm.us", "4367 Christie Way Marlboro, MA 01752", 10030));
	debtors.push_back(Debtor("Amy R. Parmer", Date("May 19, 1995"), "480-883-4934", "AmyRParmer@armyspy.com", "85 Elmwood Avenue Chandler, AZ 85249", 5347));
	debtors.push_back(Debtor("Newton K. Evans", Date("October 8, 1986"), "303-207-9084", "NewtonKEvans@rhyta.com", "3552 Columbia Road Greenwood Village, CO 80111", 9838));
	debtors.push_back(Debtor("Kathleen C. Chaney", Date("January 5, 1949"), "605-245-3513", "KathleenCChaney@rhyta.com", "316 Elsie Drive Fort Thompson, SD 57339", 1672));
	debtors.push_back(Debtor("Manuel C. Johnson", Date("February 23, 1957"), "606-247-2659", "ManuelCJohnson@jourrapide.com", "4146 May Street Sharpsburg, KY 40374", 9195));
	debtors.push_back(Debtor("Carla A. Creagh", Date("November 21, 1988"), "614-307-8974", "CarlaACreagh@dayrep.com", "3106 Bates Brothers Road Columbus, OH 43215", 11271));
	debtors.push_back(Debtor("Norma M. debtors.push_back(new", Date("May 18, 1988"), "857-492-8703", "NormaMNew@jourrapide.com", "965 Metz Lane Woburn, MA 01801", 9761));
	debtors.push_back(Debtor("Roy D. Green", Date("January 27, 1983"), "308-340-5981", "RoyDGreen@jourrapide.com", "401 Romrog Way Grand Island, NE 68801", 10771));
	debtors.push_back(Debtor("Cristy J. Jensen", Date("November 2, 1935"), "440-626-9550", "CristyJJensen@jourrapide.com", "2177 Harley Vincent Drive Cleveland, OH 44113", 5205));
	debtors.push_back(Debtor("Nancy J. Fergerson", Date("June 10, 1993"), "219-987-8498", "NancyJFergerson@dayrep.com", "3584 Jadewood Drive Demotte, IN 46310", 1276));
	debtors.push_back(Debtor("Dave N. Rodriguez", Date("January 21, 1938"), "214-540-2499", "DaveNRodriguez@rhyta.com", "1890 Poco Mas Drive Dallas, TX 75247", 9132));
	debtors.push_back(Debtor("James E. Denning", Date("May 4, 1988"), "504-289-8640", "JamesEDenning@jourrapide.com", "1444 Rose Avenue Metairie, LA 70001", 8176));
	debtors.push_back(Debtor("Richard M. Thomas", Date("February 13, 1972"), "510-735-3359", "RichardMThomas@jourrapide.com", "4454 Green Avenue Oakland, CA 94609", 7875));
	debtors.push_back(Debtor("Lakisha R. Forrest", Date("December 1, 1973"), "334-830-1181", "LakishaRForrest@armyspy.com", "3121 Quarry Drive Montgomery, AL 36117", 3088));
	debtors.push_back(Debtor("Pamela H. Beauchamp", Date("November 20, 1959"), "801-559-6347", "PamelaHBeauchamp@jourrapide.com", "3239 Tori Lane Salt Lake City, UT 84104", 6588));*/


	//2) rhyta.com ve ya dayrep.com domenlerinde emaili olan borclulari cixartmag
	//debtors.remove_if(removeByEmail);
	//for_each(begin(debtors), end(debtors), print);

	//3) Yashi 26 - dan 36 - ya qeder olan borclulari cixartmag

	//debtors.remove_if(removeByAge);
	//for_each(begin(debtors), end(debtors), print);

	//4) Borcu 5000 - den cox olmayan borclulari cixartmag

	//debtors.remove_if(removeByDebt);
	//for_each(begin(debtors), end(debtors), print);

	//5) Butov adi 18 simvoldan cox olan ve telefon nomresinde 2 ve ya 2 - den cox 7 reqemi olan borclulari cixartmaq

	//debtors.remove_if(remove_age_number);
	//for_each(begin(debtors), end(debtors), print);

	//7) Qishda anadan olan borclulari cixardmaq

	//debtors.remove_if(remove_winter);
	//for_each(begin(debtors), end(debtors), print);

	//8) Borcu, umumi borclarin orta borcunnan cox olan borclulari cixarmaq ve evvel familyaya gore sonra ise meblegin azalmagina gore sortirovka etmek
	//static float sum_debut = 0;
	//for_each(begin(debtors), end(debtors), [](Debtor& d1)->void { sum_debut += d1.get_debt(); });
	//static float avarage_debut = sum_debut/debtors.size();
	//for_each(begin(debtors), end(debtors), [](Debtor& d1)->void { if (d1.get_debt() > avarage_debut) { cout << d1 << endl; } });

	//9) Telefon nomresinde 8 olmayan borclularin yalniz familyasin, yashin ve umumi borcun meblegin cixarmaq
	//debtors.remove_if(phone_8_number);
	//for_each(begin(debtors), end(debtors), print_name);

	//11)Adinda ve familyasinda hec olmasa 3 eyni herf olan borclularin siyahisin cixarmaq ve onlari elifba sirasina gore sortirovka elemek
	//debtors.remove_if(eyni_herf);
	//sort(begin(debtors), end(debtors), sort_alphabetic);
	//for_each(begin(debtors), end(debtors), print);

	//?13)borclulardan en coxu hansi ilde dogulubsa hemin ili cixartmaq
	{
		//count_if() ve count() funksiyalari vasistesile yazmaga calisdim.Lakin ede bilmedim.
	}

	//14)Borcu en boyuk olan 5 borclunun siyahisini cixartmaq
	//static auto max_debt = max_element(begin(debtors), end(debtors), [](Debtor& d1, Debtor& d2)->bool { return d1.get_debt() < d2.get_debt(); });
	//remove_if(begin(debtors), end(debtors), [](Debtor& d1)->bool { if (d1.get_debt() == (*max_debt).get_debt()) { cout << d1 << endl << endl;  return false; }});

	//15)Butun borcu olanlarin borcunu cemleyib umumi borcu cixartmaq
	//static int sum_debut = 0;
	//for_each(begin(debtors), end(debtors), [](Debtor& d1)->void { sum_debut += d1.get_debt(); });
	//cout << sum_debut << endl;

	//16)2ci dunya muharibesin gormush borclularin siyahisi cixartmaq
	//	debtors.remove_if(dunya_muharibesi_sort);
	//for_each(begin(debtors), end(debtors), print);

	//18)Nomresinde tekrar reqemler olmayan borclularin ve onlarin borcunun meblegin cixartmaq
	//debtors.remove_if(not_same_number);
	//for_each(begin(debtors), end(debtors), print);

	//19)Tesevvur edek ki, butun borclari olanlar bugunden etibaren her ay 500 azn pul odeyecekler.Oz ad gunune kimi borcun oduyub qurtara bilenlerin siyahisin cixartmaq
	//debtors.remove_if(oz_ad_gunu_kredit);
	//for_each(begin(debtors), end(debtors), print);

	//20)Adindaki ve familyasindaki herflerden "smile" sozunu yaza bileceyimiz borclularin siyahisini cixartmaq 
	//debtors.remove_if(sort_ty_smile);
	//for_each(begin(debtors), end(debtors), print);


}
//BYVC