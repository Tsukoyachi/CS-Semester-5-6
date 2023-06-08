public class SimpleCarFactory {
    public static final String JEDI = "jedi";
    public static final String SITH = "sith";
    private int valeur = ((int) (Math.random()*100+1); // la valeur random calculée une seule fois ça ma
    static Character build(String type) throws Throwable{
        if(type.equal(JEDI)){
            return new Jedi(valeur);
        }
        else if (type.equal(SITH)){ 
            return new Sith(-1*valeur);
        }
        throw new Throwable("not a good type here....");
    }
}