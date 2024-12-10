BEGIN_CLS(lua::EventBase)
P_RO(Name)
P_RO(CanPreventAction)
P_RO(ActionPrevented)
P_RO(Stopped)
P_FUN(StopPropagation, lua::EventBase::StopPropagation)
P_FUN(PreventAction, lua::EventBase::PreventAction)
END_CLS()

BEGIN_CLS(lua::EmptyEvent)
INHERIT(lua::EventBase)
END_CLS()

BEGIN_CLS(lua::TickEvent)
INHERIT(lua::EventBase)
P(Time)
END_CLS()

BEGIN_CLS(lua::NetMessageEvent)
INHERIT(lua::EventBase)
P(Channel)
P(Payload)
P(Module)
P(RequestId)
P(UserID)
END_CLS()

BEGIN_CLS(lua::FindPathEvent)
INHERIT(lua::EventBase)
P(Path)
END_CLS()

BEGIN_CLS(lua::DoConsoleCommandEvent)
INHERIT(lua::EventBase)
P_RO(Command)
END_CLS()

