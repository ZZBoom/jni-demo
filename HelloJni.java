public class HelloJni {
  static {
    System.loadLibrary("hello"); // hello.dll (Windows) or libhello.so (Unixes)
  }
  private long mContext = 0;
  private Msg mMsg;
  public HelloJni(Msg msg) {
    mMsg = msg;
    mContext = construt();
  }
  private native long construt();
  public native void print();
}
