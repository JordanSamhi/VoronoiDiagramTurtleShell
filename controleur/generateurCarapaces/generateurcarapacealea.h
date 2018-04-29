#ifndef GENERATEURCARAPACEALEA_H
#define GENERATEURCARAPACEALEA_H

#include "generateurcarapace.h"

class GenerateurCarapaceAlea : public GenerateurCarapace{
public:
    GenerateurCarapaceAlea();
    GenerateurCarapaceAlea(Carapace *);
    vector<Point> calculPositionSites(const Bezier *) const;
};

#endif // GENERATEURCARAPACEALEA_H
