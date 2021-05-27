class  Car {
    public int  no_of_tires = 4;
    public String  bodyType = "Plastic" ;
    public void reverseGear(){
        System.Out.Println("Reverse Gear is Applied...");
    }
    public void switchOnHeadlights(){
         System.Out.Println("Headlights turned on...");
    }

}

class BMW extends Car {
    public String modelName = "X3";
    public void topSPeed(){
        System.out.Println("TopSpeed of BMW is 200 kmph");
    }
}