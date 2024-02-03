#pragma once

#include <string>

class NAW
{
public:
    NAW();
    NAW( const std::string&, const std::string&, const std::string& );
    virtual                   ~NAW();

public: // voor vraag 1:
    virtual const std::string& getNaam()                            const;
    virtual const std::string& getAdres()                           const;
    virtual const std::string& getPlaats()                          const;

public:
    int                        compareTo(const NAW& )              const;

public: // voor vraag 1:
    virtual void               setNaam( const std::string& );
    virtual void               setAdres( const std::string& );
    virtual void               setPlaats( const std::string& );

public: // voor vraag 1:
    virtual bool               heeftNaam( const std::string& )      const;
    virtual bool               heeftAdres( const std::string& )     const;
    virtual bool               heeftPlaats( const std::string& )    const;

private:
    std::string naam;
    std::string adres;
    std::string woonplaats;
};
