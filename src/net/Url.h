#ifndef __URL_H__
#define __URL_H__


#include <stdint.h>


class Url
{
public:
    constexpr static const char *kDefaultHost     = "159.89.25.216";
    constexpr static const char *kDefaultPassword = "x";
    constexpr static const char *kDefaultUser     = "leaf";
    constexpr static uint16_t kDefaultPort        = 3333;

    Url();
    Url(const char *url);
    Url(const char *host, uint16_t port, const char *user = nullptr, const char *password = nullptr, bool keepAlive = false, bool nhserver = false, int variant = -1);
    ~Url();

    inline bool isKeepAlive() const          { return m_keepAlive; }
    inline bool isnhserver() const           { return m_nhserver; }
    inline bool isValid() const              { return m_host && m_port > 0; }
    inline const char *host() const          { return m_host; }
    inline const char *password() const      { return m_password ? m_password : kDefaultPassword; }
    inline const char *user() const          { return m_user ? m_user : kDefaultUser; }
    inline int algo() const                  { return m_algo; }
    inline int variant() const               { return m_variant; }
    inline uint16_t port() const             { return m_port; }
    inline void setKeepAlive(bool keepAlive) { m_keepAlive = keepAlive; }
    inline void setnhserver(bool nhserver)   { m_nhserver = nhserver; }
    inline void setVariant(bool remixx)      { m_variant = remixx; }

    bool parse(const char *url);
    bool setUserpass(const char *userpass);
    const char *url() const;
    void adjust(int algo);
    void setPassword(const char *password);
    void setUser(const char *user);
    void setVariant(int variant);

    bool operator==(const Url &other) const;
    Url &operator=(const Url *other);

private:
    bool parseIPv6(const char *addr);

    bool m_keepAlive;
    bool m_nhserver;
    char *m_host;
    char *m_password;
    char *m_user;
    int m_algo;
    int m_variant;
    mutable char *m_url;
    uint16_t m_port;
};

#endif