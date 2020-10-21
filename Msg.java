public class Msg {
  public enum MsgType {
    Warn,
    Info;
  }
  private String mInfo;
  private MsgType mType;
  public Msg(String info, MsgType type) {
    mInfo = info;
    mType = type;
  }
}
