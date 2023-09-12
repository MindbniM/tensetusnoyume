public class Teacher {
    private String id;
    private String name;
    private int age;
    private String job;
    public Teacher(){
    };
    public Teacher(String id ,String name,int age,String job ){
        this.id=id;
        this.name=name;
        this.age=age;
        this.job=job;
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
    public void setJob(String job){
        this.job=job;
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
    public String getJob(){
        return job;
    }
    public void putTeacher(){
        System.out.println("**********");
        System.out.println("id:"+id);
        System.out.println("name:"+name);
        System.out.println("age:"+age);
        System.out.println("job:"+job);
        System.out.println("**********");
    }

}
