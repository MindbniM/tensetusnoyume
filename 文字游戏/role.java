import java.util.Random;

public class role {
    private String name;
    private int blood;
    private int Critnum;
    private int dogre;
    private int Fattack;
    private int defense;
    private int magic;
    private int G;
    private boolean defenses=false;
    private int bloodnum=3;
    public  role(){
    }
    public  role(String name,int blood,int Critnum,int dogre,int Fattack,int defense,int magic,int G){
        this.name=name;
        this.blood=blood;
        this.Critnum=Critnum;
        this.dogre=dogre;
        this.Fattack=Fattack;
        this.defense=defense;
        this.magic=magic;
        this.G=G;
    }
    public  void setrole(String name,int blood,int Critnum,int dogre,int Fattack,int defense,int magic,int G){
        this.name=name;
        this.blood=blood;
        this.Critnum=Critnum;
        this.dogre=dogre;
        this.Fattack=Fattack;
        this.defense=defense;
        this.magic=magic;
        this.G=G;
    }
    public void setname(String name){
        this.name=name;
    }
    public void setFattack(int Fattack){
        this.Fattack=Fattack;
    }
    public void setCritnum(int Critnum){
        this.Critnum=Critnum;
    }
    public void setdogre(int dogre){
        this.dogre=dogre;
    }
    public void setblood(int blood){
        this.blood=blood;
    }
    public void setdefense(int defense){
        this.defense=defense;
    }
    public void setmagic(int magic){
        this.magic=magic;
    }
    public void setG(int G){
        this.G=G;
    }
    public void setdefenses(boolean defenses){
        this.defenses=defenses;
    }
    public void setbloodnum(int bloodnum){
        this.bloodnum=bloodnum;
    }
    public String getname(){
        return name;
    }
    public int getblood(){
        return blood;
    }
    public int getCritnum(){
        return Critnum;
    }
    public int getdogre(){
        return dogre;
    }
    public int getFattack(){
        return Fattack;
    }
    public int getdefense(){
        return defense;
    }
    public int getmagic(){
        return magic;
    }
    public int getG(){
        return G;
    }
    public boolean getdefenses(){
        return defenses;
    }
    public int getbloodnum(){
        return bloodnum;
    }
    public void attack(role s){
        Random a=new Random();
        int Critnums=a.nextInt(100);
        int dogres=a.nextInt(100);
        int r=a.nextInt(this.Fattack/5)+this.Fattack;
        r-=s.getdefense();
        if(r<0){
            r=0;
        }
        if(s.getdefenses()){
            r/=5;
        }
        if(dogres<=s.dogre){
            r*=0;
            System.out.println(this.name+"攻击了"+s.name+",但"+s.name+"闪避了该攻击");
        }
        else if(Critnums<=Critnum){
            r*=2;
            System.out.println(this.name+"攻击了"+s.name+"暴击造成"+r+"伤害");
        }
        else {
            System.out.println(this.name + "攻击了" + s.name + "造成" + r + "伤害");
        }
            s.setblood(s.blood - r > 0 ? s.blood - r : 0);
            System.out.println(s.name + "还有" + s.getblood() + "的血量");
    }
    public void Ubloodnum(role s){
        if(s.getbloodnum()==0){
            System.out.println("没有血瓶了,无法回复");
            return;
        }
        s.setblood(s.getblood()+100);
        s.setbloodnum(s.getbloodnum()-1);
        System.out.printf(s.getname()+"使用药剂,回复100,"+s.getname()+"还有"+s.getblood()+ "的血量\n");
    }
}
