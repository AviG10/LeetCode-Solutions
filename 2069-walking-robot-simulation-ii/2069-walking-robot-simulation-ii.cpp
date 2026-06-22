class Robot {
private:
    int parimeter = 0;
    int pos = 0;
    int w, h;
    bool moved;
public:
    Robot(int width, int height) {
        w = width;
        h = height;
        parimeter = 2 * (w-1) + 2 * (h-1);
        moved = false;
    }
    
    void step(int num) {
        pos = (pos + num) % parimeter;
        moved = true;
    }
    
    vector<int> getPos() {
        if(pos < w) return {pos,0};
        else if(pos < w+h-1) return {w-1,pos-w+1};
        else if(pos < 2*w+h-2) return {2*w+h-pos-3,h-1};
        else return {0,2*h+2*w-pos-4}; 
    }
    
    string getDir() {
        if(pos == 0) return moved ? "South" : "East";
        else if(pos < w) return "East";
        else if(pos < w-1+h) return "North";
        else if(pos < w-1+h-1+w) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */