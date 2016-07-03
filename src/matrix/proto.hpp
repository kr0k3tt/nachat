#ifndef NATIVE_CHAT_MATRIX_PROTO_HPP_
#define NATIVE_CHAT_MATRIX_PROTO_HPP_

#include <vector>
#include <experimental/optional>

#include <QString>
#include <QJsonObject>

namespace matrix {

namespace proto {

struct Unsigned {
  std::experimental::optional<QJsonObject> prev_content;
  uint64_t age;
  std::experimental::optional<QString> transaction_id;
};

struct Event {
  QJsonObject content;
  uint64_t origin_server_ts;
  QString sender;
  QString type;
  Unsigned unsigned_;
  QString state_key;
};

struct Presence {
  std::vector<Event> events;
};

struct State {
  std::vector<Event> events;
};

struct Timeline {
  bool limited;
  QString prev_batch;
  std::vector<Event> events;
};

struct UnreadNotifications {
  uint64_t highlight_count;
  uint64_t notification_count;
};

struct AccountData {
  std::vector<Event> events;
};

struct Ephemeral {
  std::vector<Event> events;
};

struct JoinedRoom {
  QString id;
  UnreadNotifications unread_notifications;
  Timeline timeline;
  State state;
  AccountData account_data;
  Ephemeral ephemeral;
};

struct LeftRoom {
  QString id;
  Timeline timeline;
  State state;
};

struct InviteState {
  std::vector<Event> events;
};

struct InvitedRoom {
  InviteState invite_state;
};

struct Rooms {
  std::vector<JoinedRoom> join;
  std::vector<LeftRoom> leave;
  std::vector<InvitedRoom> invite;
};

struct Sync {
  QString next_batch;
  Presence presence;
  Rooms rooms;
};

}

}

#endif