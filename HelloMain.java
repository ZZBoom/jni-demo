public class HelloMain {
  public static void main(String[] args) {
    System.out.println(System.getProperty("java.library.path"));
    System.out.println("Hello World");
    String info = "yes!!";
    Msg msg = new Msg(info, Msg.MsgType.Info);
    HelloJni hello = new HelloJni(msg);
    hello.print();
  }
}
