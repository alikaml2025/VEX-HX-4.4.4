#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>

//#include "UploadFiletoDropbox.h"
//#include "DownloadFilefromDropbox.h"

bool AddsBypass = false;

//// License Key Generation Code 1
std::string GenerateRandomLicenseKeyGetKey(int length)
{
	const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string randomKey;
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < length; ++i) {
		randomKey += charset[rand() % (sizeof(charset) - 1)];
	}
	return randomKey;
}

//// License Key Generation Code 2
//std::string GenerateRandomLicenseKeyGetKey(size_t length)
//{
//    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
//    std::random_device rd;
//    std::mt19937 generator(rd());
//    std::uniform_int_distribution<> distribution(0, characters.size() - 1);
//
//    std::string licenseKey;
//    for (size_t i = 0; i < length; ++i) {
//        licenseKey += characters[distribution(generator)];
//    }a
//    return licenseKey;
//}

//const std::string filePath_FreeLicenseKey = "C:\\Windows\\System32\\Windows.UI.Xaml.txt";
const std::string filePath_FreeLicenseKey = "C:\\Windows\\System32\\gamisngtcui.dll";
//const std::string filePath_FreeLicenseKey = "C:\\Windows\\System32\\ChtBopomojoDS.txt";

void hideFileGetKey(const std::string& filePath_FreeLicenseKey) {
	std::string command = "attrib +s +h \"" + filePath_FreeLicenseKey + "\" >nul 2>&1";////hide
	system(command.c_str());
}

void unhideFileGetKey(const std::string& filePath_FreeLicenseKey) {
	std::string command = "attrib -s -h \"" + filePath_FreeLicenseKey + "\" >nul 2>&1";////show
	system(command.c_str());
}

void saveLicenseKeyAndExpirationTimeGetKey(const std::string& licenseKey, const std::string& filePath_FreeLicenseKey, int validitySeconds) {
	std::ofstream outFile(filePath_FreeLicenseKey);
	if (outFile.is_open()) {
		time_t now = time(nullptr);
		time_t expirationTime = now + validitySeconds; // Add validitySeconds in seconds
		outFile << licenseKey << "\n" << expirationTime << "\n" << now;
		outFile.close();
	}
	else {
		std::cerr << "Error opening file for writing." << std::endl;
	}
}


////////void saveLicenseKeyAndExpirationTimeGetKey(const std::string& licenseKey, const std::string& filePath_FreeLicenseKey, time_t durationInSeconds) {
////////	time_t expirationTime = time(nullptr) + durationInSeconds;  // Set expiration time
////////	std::ofstream file(filePath_FreeLicenseKey);
////////	if (file.is_open()) {
////////		file << "licenseKey: " << licenseKey << "\n";
////////		file << "expirationTime: " << expirationTime << "\n";  // Save expiration time as Unix timestamp
////////		file.close();
////////	}
////////	else {
////////		std::cerr << "Error: Could not open file to save license key and expiration time." << std::endl;
////////	}
////////}


void SaveKeyToFileGetKey(const std::string& key, const std::string& filePath) {
	std::ofstream file(filePath);
	if (file.is_open()) {
		file << key;
		file.close();
	}
}

//Code 2============================================

//Function prototypes------------
////////string gen_key();
////////string short_link(string link);
////////void browser(string link);
////////void link_get();
////////HRESULT downloadFile(string url, string file);
////////string shrink_earn(string link);

// Global variables
string rkey;

HRESULT downloadFile(std::string url, std::string file)
{
	HRESULT hr = URLDownloadToFileA(
		// (pCaller)    Pointer to IUknown instance (not needed)
		NULL
		// (szURL)      URL to the file that will be downloaded
		, url.c_str()
		// (szFileName) File name that the downloaded file will be saved.
		, file.c_str()
		// (dwReserved) Reserverd - always 0
		, 0
		// (lpfnCB)     Status callback
		, NULL
	);
	return hr;
}

string short_link(string link)
{
	string fuck = "https://shrinkme.io/api?api=098c5347872f1837d9b699d9719c1044bb3e3c52&url=";
	fuck = fuck + link;
	downloadFile(fuck, "fk.txt");
	string fk;
	ifstream inf{ "fk.txt" };
	getline(inf, fk);
	inf.close();
	if (fk.length() < 2)
	{
		DeleteFileA("fk.txt");
		return "fk";
	}
	string get_link;
	int xx = fk.find_last_of("/");
	int y = fk.find_last_of(R"(")");
	int z = y - xx;
	get_link = fk.substr(xx + 1, z - 1);
	get_link = "https://shrinke.me/" + get_link;
	DeleteFileA("fk.txt");
	return get_link;
}

string shrink_earn(string link)
{
	string fuck = "https://shrinkearn.com/api?api=66e5155a40c54a481ce9014a01b2794eda949def&url=";
	fuck = fuck + link;
	string fk;

	downloadFile(fuck, "fk.txt");
	ifstream inf{ "fk.txt" };
	getline(inf, fk);
	inf.close();
	if (fk.length() < 2)
	{
		DeleteFileA("fk.txt");
		return "fk";
	}
	string get_link;
	int xx = fk.find_last_of("/");
	int y = fk.find_last_of(R"(")");
	int z = y - xx;
	get_link = fk.substr(xx + 1, z - 1);
	get_link = "https://tii.la/" + get_link;
	DeleteFileA("fk.txt");
	return get_link;
}

void browser(string link)
{
	ShellExecuteA(0, 0, link.c_str(), 0, 0, 0);
	//ShellExecuteA(0, "open", "https://t.me/MSHARIFBPHAX", 0, 0, SW_SHOWNORMAL);
	//ShellExecuteA(0, "open", "https://discord.gg/duUTGzWQGY", 0, 0, SW_SHOWNORMAL);
	//ShellExecuteA(0, "open", "https://youtu.be/u-UqDVkLXpk", 0, 0, SW_SHOWNORMAL);
}

string gen_key()
{
	string fuck;
	for (int x = 0; x < 20; ++x)
	{
		fuck += 'A' + rand() % 26;
		fuck += 'a' + rand() % 26;
	}

	return fuck;
}



//Code 2============================================

#include <iostream>
#include <filesystem>

bool FolderExists(const std::string& folderPath)
{
	return std::filesystem::exists(folderPath) && std::filesystem::is_directory(folderPath);
}

void main_GetKey_Generate_Offline_Online()
{
	{//For cmd
		{
			//////////HWND console = GetConsoleWindow();
			//////////RECT ConsoleRect;
			//////////GetWindowRect(console, &ConsoleRect);
			////////////MoveWindow(console, ConsoleRect.top, ConsoleRect.left, NULL, 0, SW_HIDE);
			//////////MoveWindow(console, ConsoleRect.top, ConsoleRect.left, 500, 280, TRUE); //can change console size from here

			////////const std::string filePath_FreeLicenseKey = "C:\\Users\\Administrator\\Desktop\\ff\\Windows.UI.Xaml.txt";
			////////std::string licenseKey = "megHK-FREE-" + GenerateRandomLicenseKeyGetKey(16);
			////////saveLicenseKeyAndExpirationTimeGetKey(licenseKey, filePath_FreeLicenseKey, 10); // Set expiration time to 30 seconds
			////////std::cout << licenseKey << "\n\nGenerated License Key And Saved is Successful OnlyKeyGn" << std::endl;
			//////////std::cout << "Generated License Key And Saved OnlyKeyGn : " << licenseKey << std::endl;

			//////////std::string command = "attrib +s +h \"" + filePath_FreeLicenseKey + "\" >nul 2>&1";////hide
			//////////system(command.c_str());

			////////system("pause >nul");

			//////////remove(filePath_FreeLicenseKey.c_str()); // Remove the file after use
			////////ExitProcess(0);
		}
	}

	{//For imgui
		{
			//remove("C:\\Windows\\mega.lic");

			//hideFileGetKey(filePath_FreeLicenseKey);  // Hides the file
			unhideFileGetKey(filePath_FreeLicenseKey);  // Unhides the file
			//system("pause >nul");

			//const std::string filePath_FreeLicenseKey = "C:\\Windows\\System32\\Windows.UI.Xaml.txt";
			std::string licenseKey = "megCHEAT-1DAY" + GenerateRandomLicenseKeyGetKey(11);
			//saveLicenseKeyAndExpirationTimeGetKey(licenseKey, filePath_FreeLicenseKey, 30); // Set expiration time to 43200 seconds = 12h
			saveLicenseKeyAndExpirationTimeGetKey(licenseKey, filePath_FreeLicenseKey, 86400); // Set expiration time to 43200 seconds = 1day

			hideFileGetKey(filePath_FreeLicenseKey);  // Hides the file
			//unhideFileGetKey(filePath_FreeLicenseKey);  // Unhides the file
			//system("pause >nul");

			//WriteConfig("C:\\Windows\\mega.lic", str1, true);
			//ShellExecuteA(nullptr, "open", ("https://shrtfly.com/st?api=d959524dda3b6028dd066c1fc728e40e&type=1&url=https://www.google.com/search?q=" + randomKey).c_str(), nullptr, nullptr, SW_SHOWNORMAL);
			//ShellExecuteA(nullptr, "open", ("https://www.google.com/search?q=" + randomKey).c_str(), nullptr, nullptr, SW_SHOWNORMAL);
			//ShellExecuteA(nullptr, "open", ( randomKey).c_str(), nullptr, nullptr, SW_SHOWNORMAL);

			//ShellExecuteA(nullptr, "open", ("https://shrtfly.com/st?api=c5172a0738117aeb885f4e947276c8b8&type=1&url=https://www.google.com/search?q=" + randomKey).c_str(), nullptr, nullptr, SW_SHOWNORMAL);//1// https://shrtfly.com/
			//ShellExecuteA(nullptr, "open", ("https://shrinkearn.com/st?api=66e5155a40c54a481ce9014a01b2794eda949def&url=https://www.google.com/search?q=" + randomKey).c_str(), nullptr, nullptr, SW_SHOWNORMAL);//2// https://shrinkearn.com/
			//ShellExecuteA(nullptr, "open", ("https://shrinkme.io/st?api=098c5347872f1837d9b699d9719c1044bb3e3c52&url=https://www.google.com/search?q=" + randomKey).c_str(), nullptr, nullptr, SW_SHOWNORMAL);//3// https://shrinkme.io/
			//ShellExecuteA(nullptr, "open", ("https://linksly.co/st?api=5bd4ae8efd3f802491a06af0c23da1a1adc707cd&url=https://www.google.com/search?q=" + randomKey).c_str(), nullptr, nullptr, SW_SHOWNORMAL);//4// https://linksly.co/

			if (AddsBypass)
			{
				{
					if (FolderExists("C:\\Users\\Administrator\\Desktop"))
					{
						{
							unhideFileGetKey("C:\\Users\\Administrator\\Desktop\\megTEST.txt");  // Unhides the file
							SaveKeyToFileGetKey(licenseKey, "C:\\Users\\Administrator\\Desktop\\megTEST.txt");
							hideFileGetKey("C:\\Users\\Administrator\\Desktop\\megTEST.txt");  // Hides the file
							ShellExecuteA(nullptr, "open", ("C:\\Users\\Administrator\\Desktop\\megTEST.txt"), nullptr, nullptr, SW_SHOWNORMAL);
						}
					}
					else
					{
						{
							ShellExecuteA(nullptr, "open", ("https://www.google.com/search?q=" + licenseKey).c_str(), nullptr, nullptr, SW_SHOWNORMAL);

						}
					}
				}

			}
			else
			{
				{
					{
						rkey = gen_key();
						string link;
						//link = "https://www.google.com/search?q=your+key%20=" + rkey;
						link = ("https://www.google.com/search?q=" + licenseKey).c_str(), nullptr, nullptr, SW_SHOWNORMAL;
						browser(shrink_earn/*(short_exe*/(short_link(link)));
					}
				}

				{
					//////{
					//////	unhideFileGetKey("C:\\Users\\Administrator\\Desktop\\megTEST.txt");  // Unhides the file
					//////	SaveKeyToFileGetKey(licenseKey, "C:\\Users\\Administrator\\Desktop\\megTEST.txt");
					//////	hideFileGetKey("C:\\Users\\Administrator\\Desktop\\megTEST.txt");  // Hides the file
					//////	ShellExecuteA(nullptr, "open", ("C:\\Users\\Administrator\\Desktop\\megTEST.txt"), nullptr, nullptr, SW_SHOWNORMAL);
					//////}
				}

			}
		}
	}
}



#include <iostream>
#include <windows.h>
#include <wininet.h>
#include <fstream>
#include <string>

// Link with the WinINet library
#pragma comment(lib, "wininet.lib")

std::string fetchlicenseKeySellerApiFromURL(const std::string& url) {
	HINTERNET hInternet = InternetOpen(L"licenseauth Fetcher", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (!hInternet) {
		std::cerr << "InternetOpen failed!" << std::endl;
		return "";
	}

	HINTERNET hUrl = InternetOpenUrl(hInternet, std::wstring(url.begin(), url.end()).c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
	if (!hUrl) {
		std::cerr << "InternetOpenUrl failed!" << std::endl;
		InternetCloseHandle(hInternet);
		return "";
	}

	char buffer[4096];
	DWORD bytesRead;
	std::string licenseKeySellerApi;

	while (InternetReadFile(hUrl, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
		licenseKeySellerApi.append(buffer, bytesRead);
	}

	InternetCloseHandle(hUrl);
	InternetCloseHandle(hInternet);

	return licenseKeySellerApi;
}

void saveToFileOnDesktop(const std::string& content, const std::string& fileName) 
{
	char desktopPath[MAX_PATH];
	HRESULT hr = SHGetFolderPathA(NULL, CSIDL_DESKTOP, NULL, 0, desktopPath);

	if (SUCCEEDED(hr))
	{
		std::string filePath = std::string(desktopPath) + "\\" + fileName;
		std::ofstream outFile(filePath);
		if (outFile) {
			outFile << content;
			outFile.close();
			std::cout << "File saved at: " << filePath << std::endl;
		}
		else {
			std::cerr << "Error creating file!" << std::endl;
		}
	}
	else {
		std::cerr << "Error getting desktop path!" << std::endl;
	}
}

void main_GetKey_Generate_Online_SellerApi()
{
	std::string filePath;
	// URL to fetch the license key
	//1Day-----------
	//std::string url = "https://licenseauth.xyz/api/seller/?sellerkey=54ab7038d9bfbfaddb6d5ad191c48e6a&type=add&expiry=1&mask=ESPMAAZ-SL-XXXXXX-XXXXXX&level=1&amount=1&format=text";
	//12h------------
	std::string url = "https://licenseauth.xyz/api/seller/?sellerkey=54ab7038d9bfbfaddb6d5ad191c48e6a&type=add&expiry=0.5&mask=ESPMAAZ-CHEAT-12HXXXXXXXXXXXX&level=1&amount=1&format=text";
	//30s------------
	//std::string url = "https://licenseauth.xyz/api/seller/?sellerkey=54ab7038d9bfbfaddb6d5ad191c48e6a&type=add&expiry=0.000347222&mask=ESPMAAZ-SL-XXXXXX-XXXXXX&level=1&amount=1&format=text";

	// Fetch the license key
	std::string licenseKeySellerApi = fetchlicenseKeySellerApiFromURL(url);

	if (!licenseKeySellerApi.empty())
	{
		//// Save to a text file on the desktop
		//saveToFileOnDesktop(licenseKeySellerApi, "license_key.txt");

		if (AddsBypass)
		{
			{
				//ShellExecuteA(nullptr, "open", ("https://www.google.com/search?q=" + licenseKeySellerApi).c_str(), nullptr, nullptr, SW_SHOWNORMAL);

				{
					{
						unhideFileGetKey("C:\\Users\\Administrator\\Desktop\\megTEST.txt");  // Unhides the file
						//SaveKeyToFileGetKey(licenseKeySellerApi, "C:\\Users\\Administrator\\Desktop\\megTEST.txt");
						saveToFileOnDesktop(licenseKeySellerApi, "megTEST.txt");
						hideFileGetKey("C:\\Users\\Administrator\\Desktop\\megTEST.txt");  // Hides the file
						ShellExecuteA(nullptr, "open", ("C:\\Users\\Administrator\\Desktop\\megTEST.txt"), nullptr, nullptr, SW_SHOWNORMAL);
					}
				}
			}
		}
		else
		{
			{
				rkey = gen_key();
				string link;
				//link = "https://www.google.com/search?q=your+key%20=" + rkey;
				link = ("https://www.google.com/search?q=" + licenseKeySellerApi).c_str(), nullptr, nullptr, SW_SHOWNORMAL;
				browser(shrink_earn/*(short_exe*/(short_link(link)));
			}
		}


		
	}
	else 
	{
		std::cerr << "Failed to fetch license key." << std::endl;
	}

}