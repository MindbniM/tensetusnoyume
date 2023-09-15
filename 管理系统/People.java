public class People {
    private String id;
    private String name;
    private int age;
    public People(){}
    public People(String Id ,String name, int age){
        this.id=Id;
        this.age=age;
        this.name=name;
    }
    public void Peoples(String Id ,String name,int age){
        this.id=Id;
        this.name=name;
        this.age=age;
    }
    public void setId(String id){
        this.id=id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getId() {
        return id;
    }
    public String getName(){
        return name;
    }
    public int getAge(){
        return age;
    }
    public void putpeople(){
        System.out.println("**********");
        System.out.println("id:"+getId());
        System.out.println("name:"+getName());
        System.out.println("age:"+getAge());
        System.out.println("**********");
    }
}
