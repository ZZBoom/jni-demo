public class Msg {
  public enum MsgType {
    Warn,
    Info;
  }
  private String mInfo;
  private MsgType mType;
  private int ok = 0;
  public Msg(String info, MsgType type) {
    mInfo = info;
    mType = type;
    ok = 1;
  }
  public void print() {
    System.out.println("Msg.print");
    System.out.println(mInfo);
    System.out.println(mType);
  }
}
