#ifndef AGENT_H_
#define AGENT_H_
class Session;
#include <vector>

class Agent{
public:
    Agent() = default;
    virtual ~Agent()=default;
    virtual void act(Session& session)=0;
    virtual Agent* clone() const=0;
};

class ContactTracer: public Agent{
public:
    ContactTracer();
    virtual ~ContactTracer()=default;
    void act(Session& session) override;
    virtual Agent* clone() const override;
};


class Virus: public Agent{
public:
    Virus(int nodeInd);//done
    virtual ~Virus()=default;


    virtual void act(Session& session) override;
    virtual  Agent* clone() const override;//done

private:
    const int nodeInd;
};

#endif
