public class Teacher extends People{
    private String job;
    public Teacher(){
    };
    public Teacher(String id ,String name,int age,String job ){
        super(id,name,age);
        this.job=job;
    }
    public void setJob(String job){
        this.job=job;
    }
    public String getJob(){
        return job;
    }
    @Override
    public void putpeople(){
        System.out.println("**********");
        System.out.println("id:"+getId());
        System.out.println("name:"+getName());
        System.out.println("age:"+getAge());
        System.out.println("job:"+job);
        System.out.println("**********");
    }

}
