public class Solution {
   public String simplifyPath(String path) {
        String[] dirs=path.split("/+");
        //System.out.println(dirs.length);
        ArrayList<String> paths=new ArrayList<String>();
        for(int i=1;i<dirs.length;i++){
        //	System.out.println(dirs[i]);
        	if(dirs[i].equals("..")&& paths.size()>0) paths.remove(paths.size()-1);
        	else if(!dirs[i].equals(".") && !dirs[i].equals("..")) paths.add("/"+dirs[i]);
        }
        String result="";
        for(int i=0;i<paths.size();i++)
        	result += paths.get(i);
        if(paths.size()==0) result="/";
        return result;
    }
}
