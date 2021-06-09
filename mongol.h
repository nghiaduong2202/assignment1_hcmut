#pragma once
//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string input3);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////

// tìm số ký tự lặp lại trong chuỗi
int demLap(string str, char c)
{
    int temp = 0;
    for (char ch : str)
    {
        if (ch == c) temp++;
    }
    return temp;
}

// bảng mã hóa input1
char maHoaInput1(int a, int b)
{
    b = b % 7;
    switch (a)
    {
    case 00:
        switch (b)
        {
        case 1:
            return 'E';
            break;
        case 2:
            return 'F';
            break;
        case 3:
            return 'G';
            break;
        case 4:
            return 'H';
            break;
        case 5:
            return 'I';
            break;
        case 6:
            return 'J';
            break;
        case 0:
            return 'K';
            break;
        }
    case 01:
        switch (b)
        {
        case 1:
            return 'L';
            break;
        case 2:
            return 'M';
            break;
        case 3:
            return 'N';
            break;
        case 4:
            return 'O';
            break;
        case 5:
            return 'P';
            break;
        case 6:
            return 'Q';
            break;
        case 0:
            return 'R';
            break;
        }
    case 10:
        switch (b)
        {
        case 1:
            return '#';
            break;
        case 2:
            return 'T';
            break;
        case 3:
            return 'U';
            break;
        case 4:
            return 'V';
            break;
        case 5:
            return 'W';
            break;
        case 6:
            return 'X';
            break;
        case 0:
            return 'Y';
            break;
        }
    case 11:
        switch (b)
        {
        case 1:
            return '@';
            break;
        case 2:
            return 'A';
            break;
        case 3:
            return 'S';
            break;
        case 4:
            return 'Z';
            break;
        case 5:
            return 'B';
            break;
        case 6:
            return 'C';
            break;
        case 0:
            return 'D';
            break;
        }
    }
    return -1;
}

// đảo thứ tự của chuỗi
string daoThuTu(string str)
{
    string str_return;
    for (char c : str)
        str_return = c + str_return;
    return str_return;
}

// đã check
// 1000/1000
string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    // check thủ lĩnh 
    // 1 là vua trần , 2 là trần hưng đạo còn 0 là không có ai
    int thu_linh = 0;
    for (int i = 0; i < NID; i++)
    {
        if ((ID[i][0] == 'V') && (ID[i][1] == 'U') && (ID[i][2] == 'A'))
        {
            thu_linh = 1;
            break;
        }
        for (unsigned long j = 0; j < ID[i].size(); j++)
            if ((ID[i][j] == 'T') && (ID[i][j + 1] == 'H') && (ID[i][j + 2] == 'D') && (j != 0))
            {
                thu_linh = 2;
                break;
            }
        if (thu_linh != 0) break;
    }


    // mã hóa từng dòng sau đó cọng lại 
    string str_return;
    for (int z = 0; z < N1; z++)
    {
        string str;
        string inp = input1[z];
        while (inp != "\0")
        {
            int number = 0, temp = 0;
            while ((inp[temp] != ' ') && inp[temp] != '\0')
            {
                temp++;
            }

            switch (inp[0])
            {
            case '0':
                switch (inp[1])
                {
                case '0':
                    number = 0;
                    break;
                case '1':
                    number = 1;
                    break;
                }
                break;
            case '1':
                switch (inp[1])
                {
                case '0':
                    number = 10;
                    break;
                case '1':
                    number = 11;
                    break;
                }
                break;
            }
            if (inp[temp] != '\0')
                inp = inp.substr(temp + 1);
            else inp = "\0";
            str += maHoaInput1(number, temp / 2);
        }



        int size = str.size();
        int arr[1000] = { 0 };
        int temp = 0;
        string str_cp;
        // tìm số lượng ký tự # và @ trong chuỗi, đồng thời tìm vị trí của từng vị trí.
        for (int i = 0; i < size; i++)
            if ((str[i] == '#') || (str[i] == '@'))
            {
                temp++;
                arr[temp] = i;
            }
        if (temp == 0)
        {
            str_cp = str;
        }
        else
        {
            arr[temp + 1] = size;
        }

        if (arr[1] != 0)
        {
            for (int i = 0; i < arr[1]; i++)
            {
                str_cp += str[i];
            }
        }

        for (int i = 1; i <= temp; i++)
        {
            // trường hợp #
            if (str[arr[i]] == '#')
            {
                if (str[arr[i] + 1] == '\0') break;
                for (int j = arr[i] + 1; j < arr[i + 1]; j++)
                {
                    str_cp += str[j];
                }
                if (str[(arr[i + 1] - 1)] == 'Z') str_cp += 'A';
                else str_cp += (char)((int)(str[(arr[i + 1] - 1)] + 1));
            }
            // trường hợp @
            if (str[arr[i]] == '@')
            {
                string chuoi;
                for (int j = arr[i] + 1; j < arr[i + 1]; j++)
                {
                    chuoi += str[j];
                }
                str_cp += daoThuTu(chuoi);
            }
        }


        if ((str_cp.size() == 1) && ((str_cp < "A") || (str_cp > "Z")));
        else
        {
            str = "";
            // vua trần chỉ huy
            if (thu_linh == 1)
            {
                string str_chiHuy;
                if (str_cp.size() % 2 == 0)
                {
                    string str_chan, str_le;
                    for (unsigned long i = 0; i < str_cp.size(); i++)
                    {
                        if (i % 2 == 0) str_chan += str_cp[i];
                        else str_le += str_cp[i];
                    }
                    str_chan = daoThuTu(str_chan);
                    str_le = daoThuTu(str_le);
                    for (unsigned long i = 0; i < str_chan.size(); i++)
                    {
                        str_chiHuy += str_chan[i];
                        str_chiHuy += str_le[i];
                    }
                }
                else
                {
                    str_chiHuy = daoThuTu(str_cp);
                }

                for (unsigned long i = 0; i < str_cp.size(); i++)
                {
                    if ((int)str_cp[i] < (int)str_chiHuy[i]) str += str_chiHuy[i];
                    else str += str_cp[i];
                }

            }
            // trần hưng đạo chỉ huy
            if (thu_linh == 2)
            {
                for (unsigned long i = 0; i < str_cp.size(); i++)
                {
                    if (i % 3 != 0) str += str_cp[i];
                }
                for (unsigned long i = 0; i < str.size(); i++)
                    for (unsigned long j = i + 1; j < str.size(); j++)
                        if ((int)str[i] > (int)str[j])
                        {
                            char c = str[i];
                            str[i] = str[j];
                            str[j] = c;
                        }
            }
            if (thu_linh == 0)
                str = str_cp;
            if (z != N1 - 1)
                str_return += str + " ";
            else
                str_return += str;
        }
    }


    return str_return;
}



// đã check
int decode(const string A, const string B)
{
    int key = 0;
    for (unsigned long i = 0; i <= A.size() - B.size(); i++)
    {
        if (B == A.substr(i, B.size())) key++;
    }
    return key;
}
// đã check
// 1000/1000
string findRoute(const string input3)
{
    string inp = input3;
    string S;
    int N = 0, B = 0;
    string::size_type sz = 0;
    N = stoi(inp, &sz);
    inp = inp.substr(sz);
    B = stoi(inp, &sz);
    S = inp.substr(sz + 1);

    unsigned long s = S.size();
    if (B > 0)
        for (int i = 0; i < B; i++)
        {
            char thay = S[s - 1];
            for (unsigned long j = 0; j <= s; j++)
            {
                char c = S[j];
                S[j] = thay;
                thay = c;
            }
        }
    if (B < 0)
        for (int i = 0; i < abs(B); i++)
        {
            char thay = S[0];
            for (int j = s - 1; j >= 0; j--)
            {
                char c = S[j];
                S[j] = thay;
                thay = c;
            }
        }
    int x = 0, y = 0;

    for (unsigned long i = 0; i < s; i++)
    {
        int number = 0;
        switch (S[i])
        {
        case 'U':
            number = 0;
            break;
        case 'D':
            number = 1;
            break;
        case 'L':
            number = 2;
            break;
        case 'R':
            number = 3;
            break;
        }

        number += abs(N - 2 * (int)i);
        number = number % 4;

        switch (number)
        {
        case 0:
            y++;
            break;
        case 1:
            y--;
            break;
        case 2:
            x--;
            break;
        case 3:
            x++;
            break;
        }
    }
    string str;
    str = "(" + to_string(x) + "," + to_string(y) + ")";
    return str;
}
// đã check
// 1000/1000
string decodeVfunction(const string A, const string B)
{
    if (A.size() == 1) return "0";
    if (B.size() == 1) return "0";
    int tempA = 0, tempB = 0;
    tempA = demLap(A, 'V');
    tempB = demLap(B, 'V');
    string str;
    for (int i = 0; i < tempA * tempB; i++)
        str += "V(";
    str += "0";
    for (int i = 0; i < tempA * tempB; i++)
        str += ")";
    return str;
}
// đã check
// 1000/1000
string findBetrayals(const string input5[], const int N5)
{
    string str;
    int  arr[26] = { 0 };
    for (int i = 0; i < N5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            arr[(int)input5[i][j] - 65] += (6 - j);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int max = arr[0];
        for (int j = 0; j < 26; j++)
        {
            if (max < arr[j]) max = arr[j];
        }
        for (int j = 0; j < 26; j++)
        {
            if (arr[j] == max)
            {
                str += (char)(j + 65);
                arr[j] = 0;
                break;
            }
        }
    }
    return str;
}
// đã check
// 1000/1000
int attack(const string input6[])
{
    int arr[10] = { 0 };
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (input6[i][j] == '2')
            {
                arr[i] = -1;
                break;
            }
            if (input6[i][j] == '0')
                arr[i]++;
        }
    }
    int max = arr[0];
    for (int i = 1; i < 10; i++)
    {
        if (max <= arr[i]) max = arr[i];
    }
    int temp = -1;
    if (max == -1) return -1;
    for (int i = 0; i < 10; i++)
    {
        if (max == arr[i]) temp = i;
    }
    return temp;
}

// đúng 999/1000 , trường hợp cuối khác do quá thời gian quy định , vcl :'(
// cần tối ưu code khi gảnh 
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    long long arr[100][100];
    long long input[4] = { 0 };
    string inp = input7Str;
    string::size_type sz = 0;

    // lấy dữ liệu N7,V,i,j
    for (int i = 0; i < 4; i++)
    {
        input[i] = stoi(inp, &sz);
        inp = inp.substr(sz);
    }
    // check số ma trận
    if (input[0] == 1)
    {
        arr[0][0] = 1;
        for (int i = 0; i < k; i++)
        {
            int so_moi = stoi(input7Matrix[i]);
            arr[0][0] = (arr[0][0] * so_moi) % input[1];
        }
    }
    else
    {
        // gán matrix đầu thành matrix đơn vị
        for (int i = 0; i < input[0]; i++)
            for (int j = 0; j < input[0]; j++)
                if (i == j) arr[i][j] = 1;
                else arr[i][j] = 0;
        // đến số matrix
        for (int i = 0; i < k; i++)
        {
            long long array[100][100];
            for (int h = 0; h < input[0]; h++)
                for (int l = 0; l < input[0]; l++)
                    array[h][l] = 0;
            string str = input7Matrix[i];
            string::size_type kkk = 0;
            // lấy dữ liệu ra từ input7Matrix theo từng hàng
            for (int j = 0; j < input[0]; j++)
                for (int k = 0; k < input[0]; k++)
                {
                    array[j][k] = stoi(str, &kkk);
                    str = str.substr(kkk);
                }

            // tạo matrix con để thực hiện phép nhân
            long long arr_cp[100][100];
            for (int h = 0; h < input[0]; h++)
                for (int l = 0; l < input[0]; l++)
                    arr_cp[h][l] = 0;

            // nhân matrix 
            for (int j = 0; j < input[0]; j++)
                for (int k = 0; k < input[0]; k++)
                    for (int z = 0; z < input[0]; z++)
                    {
                        arr_cp[j][k] += arr[j][z] * array[z][k];
                    }
            // gán matrix thay thế vào matrix dùng để lặp
            for (int j = 0; j < input[0]; j++)
                for (int k = 0; k < input[0]; k++)
                {
                    arr[j][k] = arr_cp[j][k] % input[1];
                }

        }

    }

    long long R = arr[input[2]][input[3]] % input[1];
    if (R < 0) R = R + input[1];
    return R;
}


#endif /* MONGOL_H */
