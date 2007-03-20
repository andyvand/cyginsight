/****************************************************************************
 * Copyright � 2003-2007 Dorian C. Arnold, Philip C. Roth, Barton P. Miller *
 *                  Detailed MRNet usage rights in "LICENSE" file.          *
 ****************************************************************************/

// $Id: Mutex.h,v 1.4 2007/01/24 19:33:44 darnold Exp $
#ifndef XPLAT_MUTEX_H
#define XPLAT_MUTEX_H

namespace XPlat
{

class Mutex
{
public:
    class Data
    {
    public:
        virtual ~Data( void ) { }

        virtual int Lock( void ) = 0;
        virtual int Unlock( void ) = 0;
    };

private:
    Data* data;

public:
    Mutex( void );
    virtual ~Mutex( void )          { delete data; }

    virtual int Lock( void )        { return data->Lock(); }
    virtual int Unlock( void )      { return data->Unlock(); }
};

} // namespace XPlat

#endif // XPLAT_MUTEX_H