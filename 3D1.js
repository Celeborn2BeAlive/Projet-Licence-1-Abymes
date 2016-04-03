function base(origine, v1_x, v1_y, v2_x, v2_y)
	{
	 this.O = origine;
	 this.v1_x = v1_x;
	 this.v1_y = v1_y;
	 this.v2_x = v2_x;
	 this.v2_y = v2_y;
	}
	
	
	function point(name, x, y, base)
	{
	 this.name = name;
	 this.x = x;
	 this.y = y;
	 if(base != null) this.base = base;
	 else this.base = "O";
	}
	
	function drawLine(point1, point2, color)
	{
	 if(point1.base != "0")
	 {
	  p1.x = ((point1.base.v1_x)*point1.x  + (point1.base.v2_x)*point1.y) + point1.base.O.x;
	  p1.y = ((point1.base.v1_y)*point1.x  + (point1.base.v2_y)*point1.y) + point1.base.O.y;
	 }
	 else
	 {
	  p1.x = point1.x;
	  p1.y = point1.y;
	 }
	 
	 if(point2.base != "0")
	 {
	  p2.x = ((point2.base.v1_x)*point2.x  + (point1.base.v2_x)*point2.y) + point2.base.O.x;
	  p2.y = ((point2.base.v1_y)*point2.x  + (point1.base.v2_y)*point2.y) + point2.base.O.y;
	 }
	 else
	 {
	  p2.x = point2.x;
	  p2.y = point2.y;
	 }
	
	
	 var new_ligne = document.getElementById("ligne_tronc").cloneNode(true);
	 new_ligne.setAttribute("id", p1.name+p2.name);
	 new_ligne.setAttribute("x1", p1.x);
	 new_ligne.setAttribute("y1", p1.y);
	 new_ligne.setAttribute("x2", p2.x);
	 new_ligne.setAttribute("y2", p2.y);
	 
	 
	 if(color == null) nouvelle_ligne.setAttribute("stroke", "black");
	 else nouvelle_ligne.setAttribute("stroke", color);
	 
	 
	 nouvelle_ligne.setAttribute("stroke-width", "1");
	 
	 document.getElementById("scene").appendChild(nouvelle_ligne);
	}
	
	
	