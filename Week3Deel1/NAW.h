#pragma once

#include <string>

/*
 * copieer gegevens van week 1 met eventuele aanvullingen
 */

class NAW
{
public:
                               NAW();
                               NAW( const std::string&, const std::string&, const std::string& );
    virtual                   ~NAW();

public: // hint vooraf:
    int                        compareTo( const NAW& )              const;

// copieer de implementaties van week 1 deel 1...
public:
    virtual const std::string& getNaam()                            const;
    virtual const std::string& getAdres()                           const;
    virtual const std::string& getPlaats()                          const;

public:
    virtual void               setNaam( const std::string& );
    virtual void               setAdres( const std::string& );
    virtual void               setPlaats( const std::string& );

public:
    virtual bool               heeftNaam( const std::string& )      const;
    virtual bool               heeftAdres( const std::string& )     const;
    virtual bool               heeftPlaats( const std::string& )    const;

private:
    std::string                nonsense; // haal deze zin weg en vervang 'm door nuttige attriuten
};

