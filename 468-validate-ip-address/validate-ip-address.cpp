class Solution {
public:
    string validIPAddress(string queryIP) {
        // IPv4 regex
        string ip = 
            "^(0|[1-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])"
            "(\\.(0|[1-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])){3}$";

        regex ipv4(ip);

        // IPv6 regex (fixed {1,4})
        regex ipv6("^([0-9a-fA-F]{1,4})(:([0-9a-fA-F]{1,4})){7}$");
                
        if (regex_match(queryIP, ipv4)) return "IPv4";
        if (regex_match(queryIP, ipv6)) return "IPv6";

        return "Neither";
    }
};
