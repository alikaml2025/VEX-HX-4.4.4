#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>

#include "GetKey_Generate_Offline_Online.h"

#include "api/KeyAuth.hpp"
#include "api/Swifty.hpp"
#include "api/Swifty_hor.hpp"

bool login = true;
//bool login = false;
bool Login_Bypass = false;
char str1[60] = "";
bool SaveUsers = true;
bool savekey = true;
bool hideKey = true;

using namespace std;
using namespace KeyAuth;

////licenseauth Login...
std::string name = XorStr("meg_HAX_PVT");
std::string ownerid = XorStr("q8Vil2k1vw");
std::string secret = XorStr("a0109b50ffab4a6549c7efbc0e78b20c24bfb240eccee8a2bca6273399ad5e35");
std::string version = XorStr("1.0");
////this api https://licenseauth.xyz/api/1.0/
api OnlineApiLogin(name, ownerid, secret, version);
//OnlineApiLogin.init();

//////Chiper Login...
c_auth::api OnlineApiLogin1(XorStr("mega_Bymeg"), XorStr("1.0.1"), XorStr("qthdydpxlmi9f34vnwjd5d6octw3db2c"), XorStr("614341"));
////OnlineApiLogin1.init();

inline bool FileExistLogin_imgui(const std::string& name) {
    if (FILE* file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }
    else {
        return false;
    }
}

void Esp::LoadConfig(std::string Path) {
    CSimpleIniA ini;
    ini.SetUnicode();
    SI_Error rc = ini.LoadFile(Path.c_str());
    //	if (rc < 0) { std::cout << "File not found"; };
    if (FileExistLogin_imgui(Path))
    {
        hideKey = ini.GetBoolValue("hideKey", "hideKey");
        bool State = ini.GetBoolValue("Key", "UserKeyState");
        if (State == true)
        {
            std::string Key = ini.GetValue("Key", "UserKey");
            if (Key != "")
            {
                strcpy(str1, Key.c_str());
                SaveUsers = true;
            }
        }
    }
    /* if (ini.GetValue("Key", "UserKey")=="123")
     {

     }*/
}

void WriteConfig(std::string Path, std::string Key, bool State)
{
    CSimpleIniA ini;
    ini.SetUnicode();
    SI_Error rc = ini.LoadFile(Path.c_str());
    if (rc < 0) {
        //	std::cout << "File not found";
    };
    if (State == true)
    {
        ini.SetBoolValue("Key", "UserKeyState", true);
    }
    else
    {
        ini.SetBoolValue("Key", "UserKeyState", false);
    }
    ini.SetBoolValue("hideKey", "hideKey", hideKey);
    ini.SetValue("Key", "UserKey", Key.c_str());

    ini.SaveFile(Path.c_str());
}


bool loadLicenseKeyAndExpirationLogin_imgui(const std::string& filePath_FreeLicenseKey, std::string& licenseKey, time_t& expirationTime, time_t& lastKnownTime) {
    std::ifstream inFile(filePath_FreeLicenseKey);
    if (inFile.is_open()) {
        if (std::getline(inFile, licenseKey) && (inFile >> expirationTime) && (inFile >> lastKnownTime)) {
            inFile.close();
            return true;
        }
        inFile.close();
    }
    return false;
}

bool verifyLicenseKeyLogin_imgui(const std::string& enteredKey, const std::string& storedKey) {
    return enteredKey == storedKey;
}

bool isLicenseExpiredLogin_imgui(const time_t expirationTime) {
    time_t now = time(nullptr);
    return now > expirationTime;
}

bool isTimeTamperedLogin_imgui(const time_t lastKnownTime) {
    time_t now = time(nullptr);
    return now < lastKnownTime;
}

////====================================================================

#include <ctime>
#include <iostream>
#include <string>

bool licenseExpired = false;
bool warningDisplayed = false;
bool warningSent = false;

time_t readExpirationTimeFromFile_Vip_Free(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open license key file." << std::endl;
        return 0;
    }

    std::string licenseKey;
    std::string expirationTimeStr1;
    std::string expirationTimeStr2;

    std::getline(file, licenseKey);  // First line (License Key)
    std::getline(file, expirationTimeStr1);  // Second line (Expiration Time 1)
    std::getline(file, expirationTimeStr2);  // Third line (Expiration Time 2)

    file.close();
    time_t expirationTime = std::stol(expirationTimeStr1);
    return expirationTime;
}

void checkLicenseExpiration_Vip_Free(time_t expirationTime)
{
    time_t now = time(nullptr);
    double secondsRemaining = difftime(expirationTime, now);

    // If the license has expired, set the global flag
    if (secondsRemaining <= 0) {
        licenseExpired = true;
        warningDisplayed = false; // Reset warning if expired
    }
    else if (secondsRemaining <= 300 && !warningDisplayed) {
        // Activate warning only if within the last 5 seconds and warning has not been displayed
        warningDisplayed = true;
    }
    else if (secondsRemaining > 300) {
        warningDisplayed = false; // Reset warning if more than 5 seconds remaining
    }
}

void displayTimeDifferenceInImGui_Vip_Free(time_t expirationTime)
{
    // Check if the license has expired
    if (licenseExpired)
    {
        ImGui::TextColored(ImVec4(255, 0, 0, 255), "License has expired!");
        ExitProcess(0);
        //return; // Stop further processing
    }

    time_t now = time(nullptr);
    double secondsRemaining = difftime(expirationTime, now);

    if (warningDisplayed)
    {
        int years = static_cast<int>(secondsRemaining) / (365 * 24 * 3600);
        secondsRemaining -= years * 365 * 24 * 3600;

        int months = static_cast<int>(secondsRemaining) / (30 * 24 * 3600);
        secondsRemaining -= months * 30 * 24 * 3600;

        int days = static_cast<int>(secondsRemaining) / (24 * 3600);
        secondsRemaining -= days * 24 * 3600;

        int hours = static_cast<int>(secondsRemaining) / 3600;
        secondsRemaining -= hours * 3600;

        int minutes = static_cast<int>(secondsRemaining) / 60;
        secondsRemaining -= minutes * 60;

        int seconds = static_cast<int>(secondsRemaining);

        ImGui::SetCursorPosX(230.f);
        std::string timeRemaining = ICON_FA_CLOCK" Expires In : " +
            std::to_string(years) + " Yer, " +
            std::to_string(months) + " Mon, " +
            std::to_string(days) + " Day, " +
            std::to_string(hours) + " Hr, " +
            std::to_string(minutes) + " Min, " +
            std::to_string(seconds) + "s.";
        ImGui::TextColored(ImVec4(255, 0, 0, 255), timeRemaining.c_str());

        ImGui::SetCursorPosX(230.f);
        ImGui::TextColored(ImVec4(255, 255, 0, 255), "Warning :- Hack Will Be Closed Automatically.");
        ImGui::SameLine();
        std::string timeRemainingWarning = std::to_string(minutes) + " Min, " + std::to_string(seconds) + "s.";
        ImGui::TextColored(ImVec4(255, 0, 0, 255), timeRemainingWarning.c_str());

        ////FOR CMD
        /*std::cout << "\rLicense expires in: "
            << years << " Years, "
            << months << " Months, "
            << days << " Days, "
            << hours << " Hours, "
            << minutes << " Minutes, "
            << seconds << " Seconds." << std::flush;*/
    }
    else
    {
        int years = static_cast<int>(secondsRemaining) / (365 * 24 * 3600);
        secondsRemaining -= years * 365 * 24 * 3600;

        int months = static_cast<int>(secondsRemaining) / (30 * 24 * 3600);
        secondsRemaining -= months * 30 * 24 * 3600;

        int days = static_cast<int>(secondsRemaining) / (24 * 3600);
        secondsRemaining -= days * 24 * 3600;

        int hours = static_cast<int>(secondsRemaining) / 3600;
        secondsRemaining -= hours * 3600;

        int minutes = static_cast<int>(secondsRemaining) / 60;
        secondsRemaining -= minutes * 60;

        int seconds = static_cast<int>(secondsRemaining);

        ImGui::SetCursorPosX(230.f);
        std::string timeRemaining = ICON_FA_CLOCK" Expires In : " +
            std::to_string(years) + " Yer, " +
            std::to_string(months) + " Mon, " +
            std::to_string(days) + " Day, " +
            std::to_string(hours) + " Hr, " +
            std::to_string(minutes) + " Min, " +
            std::to_string(seconds) + "s.";

        ImGui::TextColored(ImVec4(255, 255, 0, 255), timeRemaining.c_str());

        ////FOR CMD
        /*std::cout << "\rLicense expires in: "
            << years << " Years, "
            << months << " Months, "
            << days << " Days, "
            << hours << " Hours, "
            << minutes << " Minutes, "
            << seconds << " Seconds." << std::flush;*/
    }


    if (warningDisplayed)
    {

    }
    else
    {

    }
}

void displayTimeDifferenceInImGui_Vip_Free_Down(time_t expirationTime)
{
    // Check if the license has expired
    if (licenseExpired)
    {
        ImGui::TextColored(ImVec4(255, 0, 0, 255), "License has expired!");
        ExitProcess(0);
        //return; // Stop further processing
    }

    time_t now = time(nullptr);
    double secondsRemaining = difftime(expirationTime, now);

    if (warningDisplayed)
    {
        int years = static_cast<int>(secondsRemaining) / (365 * 24 * 3600);
        secondsRemaining -= years * 365 * 24 * 3600;

        int months = static_cast<int>(secondsRemaining) / (30 * 24 * 3600);
        secondsRemaining -= months * 30 * 24 * 3600;

        int days = static_cast<int>(secondsRemaining) / (24 * 3600);
        secondsRemaining -= days * 24 * 3600;

        int hours = static_cast<int>(secondsRemaining) / 3600;
        secondsRemaining -= hours * 3600;

        int minutes = static_cast<int>(secondsRemaining) / 60;
        secondsRemaining -= minutes * 60;

        int seconds = static_cast<int>(secondsRemaining);

        ImGui::SetCursorPosX(10.f);
        std::string timeRemaining = ICON_FA_CLOCK" Expires In : " +
            std::to_string(years) + " Yer, " +
            std::to_string(months) + " Mon, " +
            std::to_string(days) + " Day, " +
            std::to_string(hours) + " Hr, " +
            std::to_string(minutes) + " Min, " +
            std::to_string(seconds) + "s.";
        ImGui::TextColored(ImVec4(255, 0, 0, 255), timeRemaining.c_str());

        /*ImGui::SetCursorPosX(230.f);
        ImGui::TextColored(ImVec4(255, 255, 0, 255), "Warning :- Hack Will Be Closed Automatically.");
        ImGui::SameLine();
        std::string timeRemainingWarning = std::to_string(minutes) + " Min, " + std::to_string(seconds) + "s.";
        ImGui::TextColored(ImVec4(255, 0, 0, 255), timeRemainingWarning.c_str());*/

        ////FOR CMD
        /*std::cout << "\rLicense expires in: "
            << years << " Years, "
            << months << " Months, "
            << days << " Days, "
            << hours << " Hours, "
            << minutes << " Minutes, "
            << seconds << " Seconds." << std::flush;*/
    }
    else
    {
        int years = static_cast<int>(secondsRemaining) / (365 * 24 * 3600);
        secondsRemaining -= years * 365 * 24 * 3600;

        int months = static_cast<int>(secondsRemaining) / (30 * 24 * 3600);
        secondsRemaining -= months * 30 * 24 * 3600;

        int days = static_cast<int>(secondsRemaining) / (24 * 3600);
        secondsRemaining -= days * 24 * 3600;

        int hours = static_cast<int>(secondsRemaining) / 3600;
        secondsRemaining -= hours * 3600;

        int minutes = static_cast<int>(secondsRemaining) / 60;
        secondsRemaining -= minutes * 60;

        int seconds = static_cast<int>(secondsRemaining);

        ImGui::SetCursorPosX(10.f);
        std::string timeRemaining = ICON_FA_CLOCK" Expires In : " +
            std::to_string(years) + " Yer, " +
            std::to_string(months) + " Mon, " +
            std::to_string(days) + " Day, " +
            std::to_string(hours) + " Hr, " +
            std::to_string(minutes) + " Min, " +
            std::to_string(seconds) + "s.";

        ImGui::TextColored(ImVec4(0, 255, 255, 255), timeRemaining.c_str());

        ////FOR CMD
        /*std::cout << "\rLicense expires in: "
            << years << " Years, "
            << months << " Months, "
            << days << " Days, "
            << hours << " Hours, "
            << minutes << " Minutes, "
            << seconds << " Seconds." << std::flush;*/
    }


    if (warningDisplayed)
    {

    }
    else
    {

    }
}

auto GetExpiry = [=]()
{
    if (Setting::ExpiresDatesVIP)
    {
        {
            {
                time_t expiryTime = mktime(&OnlineApiLogin.user_data.expiry);

                std::chrono::system_clock::time_point expiryPoint = std::chrono::system_clock::from_time_t(expiryTime);
                std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
                auto secondsRemaining = std::chrono::duration_cast<std::chrono::seconds>(expiryPoint - now).count();

                int years = static_cast<int>(secondsRemaining) / (365 * 24 * 3600);
                secondsRemaining -= years * 365 * 24 * 3600;
                int months = static_cast<int>(secondsRemaining) / (30 * 24 * 3600);
                secondsRemaining -= months * 30 * 24 * 3600;
                int days = static_cast<int>(secondsRemaining) / (24 * 3600);
                secondsRemaining -= days * 24 * 3600;
                int hours = static_cast<int>(secondsRemaining) / 3600;
                secondsRemaining -= hours * 3600;
                int minutes = static_cast<int>(secondsRemaining) / 60;
                secondsRemaining -= minutes * 60;
                int seconds = static_cast<int>(secondsRemaining);

                /*ImGui::SetCursorPosX(230.f);*/
                std::string timeRemaining;
                return std::string(timeRemaining = ICON_FA_CLOCK" Expires In : ") +
                    std::to_string(years) + " Yer, " +
                    std::to_string(months) + " Mon, " +
                    std::to_string(days) + " Day, " +
                    std::to_string(hours) + " Hr, " +
                    std::to_string(minutes) + " Min, " +
                    std::to_string(seconds) + "s.";
            }
        }
        
    }

    if (Setting::ExpiresDatesFree)
    {
        {
            {
                std::string filePath = filePath_FreeLicenseKey;
                time_t expiryTime = readExpirationTimeFromFile_Vip_Free(filePath);

                std::chrono::system_clock::time_point expiryPoint = std::chrono::system_clock::from_time_t(expiryTime);
                std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
                auto secondsRemaining = std::chrono::duration_cast<std::chrono::seconds>(expiryPoint - now).count();

                int years = static_cast<int>(secondsRemaining) / (365 * 24 * 3600);
                secondsRemaining -= years * 365 * 24 * 3600;
                int months = static_cast<int>(secondsRemaining) / (30 * 24 * 3600);
                secondsRemaining -= months * 30 * 24 * 3600;
                int days = static_cast<int>(secondsRemaining) / (24 * 3600);
                secondsRemaining -= days * 24 * 3600;
                int hours = static_cast<int>(secondsRemaining) / 3600;
                secondsRemaining -= hours * 3600;
                int minutes = static_cast<int>(secondsRemaining) / 60;
                secondsRemaining -= minutes * 60;
                int seconds = static_cast<int>(secondsRemaining);

                /*ImGui::SetCursorPosX(230.f);*/
                std::string timeRemaining;
                return std::string(timeRemaining = ICON_FA_CLOCK" Expires In : ") +
                    std::to_string(years) + " Yer, " +
                    std::to_string(months) + " Mon, " +
                    std::to_string(days) + " Day, " +
                    std::to_string(hours) + " Hr, " +
                    std::to_string(minutes) + " Min, " +
                    std::to_string(seconds) + "s.";
            }
        }
    }
};

////====================================================================

void CountdownLogin_imgui(int seconds)
{
    while (seconds > 0)
    {
        std::cout << "\rTime remaining: " << seconds << " seconds" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        --seconds;
    }
}

void CountdownLogin_imguiToExpiration(time_t expirationTime)
{
    while (true) {
        //int seconds(3);
        time_t now = time(nullptr);
        if (now >= expirationTime) {
            std::cout << """" << std::endl;
            std::cout << "\nLicense Key Expired! | Code 1 \n" << std::endl;
            //CountdownLogin_imgui(seconds);
            std::cout << """" << std::endl;
            ExitProcess(0);
            break;
        }
        displayTimeDifferenceInImGui_Vip_Free(expirationTime);

        std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for 1 second before updating the display
    }
}

void hideFileLogin_imgui(const std::string& filePath_FreeLicenseKey) {
    std::string command = "attrib +s +h \"" + filePath_FreeLicenseKey + "\" >nul 2>&1";////hide
    system(command.c_str());
}

void unhideFileLogin_imgui(const std::string& filePath_FreeLicenseKey) {
    std::string command = "attrib -s -h \"" + filePath_FreeLicenseKey + "\" >nul 2>&1";////show
    system(command.c_str());
}

void Login_Page_Bypass()
{
    ////////Login Page Bypass...................................................................................................
    login = true;	////KeyAuth
    //Setting::ShowMenu = false;
    //Utility::ChangeClickability(FALSE, DX11Window::hWindow);
    //DX11Window::IsClickable = !DX11Window::IsClickable;

}

#include <iostream>
#include <Windows.h>
#include <string>
#include <wininet.h>
#pragma comment(lib, "wininet.lib")

bool UpdateCheckingCode1(const std::string& url, std::string& result)
{
    HINTERNET hInternet = InternetOpen(L"MyUserAgent", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (!hInternet) return false;

    HINTERNET hConnect = InternetOpenUrl(hInternet, std::wstring(url.begin(), url.end()).c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (!hConnect)
    {
        InternetCloseHandle(hInternet);
        return false;
    }

    char buffer[4096];
    DWORD bytesRead;
    while (InternetReadFile(hConnect, buffer, sizeof(buffer) - 1, &bytesRead) && bytesRead != 0)
    {
        buffer[bytesRead] = 0;
        result.append(buffer);
    }

    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);

    return true;
}

void Login_Page_Bypass_CheckingCode1()
{
    std::cout << "Update Checking Code 1...\n";
    std::string url = "https://dl.dropboxusercontent.com/s/3fyrlka76l1il1ed86stb/Login_Page_Bypass_ESPMAAZ-CHEAT.txt?rlkey=m3o11acc3s45pf7z92wo1kwsc";//Check Ok, =0,=1 for Direct download
    //std::string url = "https://www.dropbox.com/scl/fi/3fyrlka76l1il1ed86stb/Login_Page_Bypass_ESPMAAZ-CHEAT.txt?rlkey=m3o11acc3s45pf7z92wo1kwsc&dl=1";//Check OK, =1 check or Direct download
    std::string content;
    if (UpdateCheckingCode1(url, content) && content.find("4.2.1.1") != std::string::npos)
        /*if (UpdateCheckingCode1(url, content) && content.find("Login_Page_OFF") != std::string::npos || UpdateCheckingCode1(url, content) && content.find("Login_Page_Off") != std::string::npos
            || UpdateCheckingCode1(url, content) && content.find("Login_Page_off") != std::string::npos)*/
    {
        ////////Login Page Bypass...................................................................................................
        //login = true;	////KeyAuth

    }
    else//Login_Page_ON
    {
        //remove(Write_Load_License_Key_Config.c_str()); // Remove the file after use
        remove("C:\\Windows\\meg-Setting.ini"); // Remove the file after use

        //ShellExecute(NULL, L"open", L"https://t.me/megsojib", NULL, NULL, SW_SHOWNORMAL);
        ShellExecute(NULL, L"open", L"https://drive.google.com/drive/folders/1NRo8cZn8-ZP69pSMdWrMlq8MZHvTkGXc?usp=sharing", NULL, NULL, SW_SHOWNORMAL);
        ExitProcess(1);
    }

    return;
}

void main_GetKeyAndOnlineLogin_imgui()
{
    if (Login_Bypass)
    {
        ////////Login Page Bypass...................................................................................................

        Setting::VipUser = true;
        login = true;
        //Setting::ShowMenu = false;
        //Utility::ChangeClickability(FALSE, DX11Window::hWindow);
        //DX11Window::IsClickable = !DX11Window::IsClickable;
    }
    else
    {
        int seconds(3);
        std::string licenseKey;
        time_t expirationTime = 0;
        time_t lastKnownTime = 0;
        bool licenseExists = loadLicenseKeyAndExpirationLogin_imgui(filePath_FreeLicenseKey, licenseKey, expirationTime, lastKnownTime);

        {
            ////Free GetKey Offline
            {
                {
                    if (licenseExists && !isTimeTamperedLogin_imgui(lastKnownTime))
                    {
                        if (verifyLicenseKeyLogin_imgui(str1, licenseKey))
                        {
                            if (!isLicenseExpiredLogin_imgui(expirationTime))
                            {
                                std::cout << "Login successful!" << std::endl;
                                login = true;

                                Setting::VipUser = false;
                                Setting::ExpiresDatesVIP = false;
                                Setting::ExpiresDatesFree = true;

                                WriteConfig("C:\\Windows\\mega.lic", str1, true);

                                hideFileLogin_imgui(filePath_FreeLicenseKey);  // Hides the file
                                ////unhideFileLogin_imgui(filePath_FreeLicenseKey);  // Unhides the file
                                //system("pause >nul");

                                if (Setting::VipUser) {
                                    ImGui::InsertNotification({ ImGuiToastType_SuccessServer1, 5000, " Login is a success! %s", "You Are Vip User " });
                                }
                                else {
                                    ImGui::InsertNotification({ ImGuiToastType_SuccessServer2, 5000, " Login is a success! %s", "You Are Free User " });
                                }

                                {
                                    if (FileExistLogin_imgui("C:\\Windows\\meg-Setting.ini"))
                                    {
                                        LoadConfiggg("C:\\Windows\\meg-Setting.ini");
                                        ImGui::InsertNotification({ ImGuiToastType_Success, 7000, " Load Setting is Success! %s", "" });
                                    }
                                    else
                                    {
                                        ImGui::InsertNotification({ ImGuiToastType_Warning, 7000, " Your Config not saved yet! %s", "" });
                                    }
                                }
                            }
                            else
                            {
                                hideFileLogin_imgui(filePath_FreeLicenseKey);  // Hides the file
                                //unhideFileLogin_imgui(filePath_FreeLicenseKey);  // Unhides the file
                                //system("pause >nul");
                                remove(filePath_FreeLicenseKey.c_str()); // Remove the file after use
                                remove("C:\\Windows\\mega.lic"); // Remove the file after use

                                ImGui::InsertNotification({ ImGuiToastType_ErrorCode2, 7000, " Key is Expired...! Try Again New Key! %s", "" });
                            }
                        }
                        else
                        {
                            hideFileLogin_imgui(filePath_FreeLicenseKey);  // Hides the file
                            //unhideFileLogin_imgui(filePath_FreeLicenseKey);  // Unhides the file
                            //system("pause >nul");
                            //remove(filePath_FreeLicenseKey.c_str()); // Remove the file after use

                            //ImGui::InsertNotification({ ImGuiToastType_Warning, 5000, " Key is invalid...! Try Again Thank You! %s", "" });

                            OnlineApiLogin.init();

                            ////Chiper Login...
                            //OnlineApiLogin1.init();
                            //if (OnlineApiLogin1.licenselogin(str1))

                            if (OnlineApiLogin.license(str1))
                            {
                                login = true;	////Main Menu Open

                                Setting::VipUser = true;
                                Setting::ExpiresDatesVIP = true;
                                Setting::ExpiresDatesFree = false;

                                WriteConfig("C:\\Windows\\mega.lic", str1, true);

                                if (Setting::VipUser) {
                                    ImGui::InsertNotification({ ImGuiToastType_SuccessServer1, 5000, " Login is a success! %s", "You Are Vip User " });
                                }
                                else {
                                    ImGui::InsertNotification({ ImGuiToastType_SuccessServer2, 5000, " Login is a success! %s", "You Are Free User " });
                                }

                                {
                                    if (FileExistLogin_imgui("C:\\Windows\\meg-Setting.ini"))
                                    {
                                        LoadConfiggg("C:\\Windows\\meg-Setting.ini");
                                        ImGui::InsertNotification({ ImGuiToastType_Success, 7000, " Load Setting is Success! %s", "" });
                                    }
                                    else
                                    {
                                        ImGui::InsertNotification({ ImGuiToastType_Warning, 7000, " Your Config not saved yet! %s", "" });
                                    }
                                }
                            }
                            else
                            {
                                ImGui::InsertNotification({ ImGuiToastType_Error, 5000, " Key is invalid...! Try Again Or Use Another Key! %s", "" });
                            }
                        }
                    }
                    else
                    {
                        if (!licenseExists)
                        {
                            hideFileLogin_imgui(filePath_FreeLicenseKey);  // Hides the file
                            //unhideFileLogin_imgui(filePath_FreeLicenseKey);  // Unhides the file
                            //system("pause >nul");
                            //remove(filePath_FreeLicenseKey.c_str()); // Remove the file after use

                            //ImGui::InsertNotification({ ImGuiToastType_ErrorCode1, 5000, " Key is invalid...! Try Again New Key! %s", "" });

                            OnlineApiLogin.init();

                            ////Chiper Login...
                            //OnlineApiLogin1.init();
                            //if (OnlineApiLogin1.licenselogin(str1))

                            if (OnlineApiLogin.license(str1))
                            {
                                login = true;	////Main Menu Open

                                Setting::VipUser = true;
                                Setting::ExpiresDatesVIP = true;
                                Setting::ExpiresDatesFree = false;

                                WriteConfig("C:\\Windows\\mega.lic", str1, true);

                                if (Setting::VipUser) {
                                    ImGui::InsertNotification({ ImGuiToastType_SuccessServer1, 5000, " Login is a success! %s", "You Are Vip User " });
                                }
                                else {
                                    ImGui::InsertNotification({ ImGuiToastType_SuccessServer2, 5000, " Login is a success! %s", "You Are Free User " });
                                }

                                {
                                    if (FileExistLogin_imgui("C:\\Windows\\meg-Setting.ini"))
                                    {
                                        LoadConfiggg("C:\\Windows\\meg-Setting.ini");
                                        ImGui::InsertNotification({ ImGuiToastType_Success, 7000, " Load Setting is Success! %s", "" });
                                    }
                                    else
                                    {
                                        ImGui::InsertNotification({ ImGuiToastType_Warning, 7000, " Your Config not saved yet! %s", "" });
                                    }
                                }
                            }
                            else
                            {
                                ImGui::InsertNotification({ ImGuiToastType_Error, 5000, " Key is invalid...! Try Again Or Use Another Key! %s", "" });
                            }
                        }
                        else  if (isTimeTamperedLogin_imgui(lastKnownTime))
                        {
                            hideFileLogin_imgui(filePath_FreeLicenseKey);  // Hides the file
                            //unhideFileLogin_imgui(filePath_FreeLicenseKey);  // Unhides the file
                            //system("pause >nul");
                            remove(filePath_FreeLicenseKey.c_str()); // Remove the file after use
                            remove("C:\\Windows\\mega.lic"); // Remove the file after use

                            ImGui::InsertNotification({ ImGuiToastType_ErrorCode1, 5000, " System Time Tampering Detected! Your Attempt Failed! %s", "" });
                            ImGui::InsertNotification({ ImGuiToastType_Warning, 7000, " Do not retry it, Retrying may result in banning of your hardware ID! %s", "" });
                            ExitProcess(0);
                        }
                    }
                }
            }
        }
    }
}