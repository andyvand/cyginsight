/****************************************************************************
 * Copyright � 2003-2007 Dorian C. Arnold, Philip C. Roth, Barton P. Miller *
 *                  Detailed MRNet usage rights in "LICENSE" file.          *
 ****************************************************************************/

#if !defined(__communicator_h)
#define __communicator_h 1

#include <vector>

#include "mrnet/MRNet.h"

namespace MRN
{

class RemoteNode;
class CommunicatorImpl{
    friend class Stream;
    friend class Network;
    friend class Communicator;

 private:
    Network * network;
    std::vector <RemoteNode *> downstream_nodes; 
    std::vector <EndPoint *> endpoints;  //BackEnds addressed by communicator

    // used to construct broadcast communicator
    CommunicatorImpl( Network * );
    CommunicatorImpl( Network *, Communicator &);
    CommunicatorImpl( Network *, const std::vector<EndPoint*>& eps );

 public:
    ~CommunicatorImpl( void );

    const std::vector <EndPoint *> & get_EndPoints() const;

    int add_EndPoint(const char * hostname, Port port);
    int add_EndPoint(Rank _rank);
    void add_EndPoint(EndPoint *);

    unsigned int size() const;
    const char * get_HostName(int) const; 
    Port get_Port(int) const;
    Rank get_Rank(int) const;
};

inline void CommunicatorImpl::add_EndPoint(EndPoint * new_endpoint)
{
    endpoints.push_back(new_endpoint);
}

inline unsigned int CommunicatorImpl::size(void) const
{
    return endpoints.size();
}

inline const char * CommunicatorImpl::get_HostName(int id) const
{
    return endpoints[id]->get_HostName();
}

inline Port CommunicatorImpl::get_Port(int id) const
{
    return endpoints[id]->get_Port();
}

inline Rank CommunicatorImpl::get_Rank(int id) const
{
    return endpoints[id]->get_Rank();
}

inline const std::vector <EndPoint *> & CommunicatorImpl::get_EndPoints() const
{
  return endpoints;
}

} // namespace MRN

#endif /* __communicator_h */
