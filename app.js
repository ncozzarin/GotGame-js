function Jugador(nombre){
    this.nombre = nombre;
    this.hp = 100;
    this.sp = 100;

    this.curar = function(jugadorObjetivo){
        
        if (this.sp >= 40){
            this.sp -= 40;
            jugadorObjetivo.hp += 20;
        }else{
            console.info(this.nombre + " " + "No posee mas SP")
        }
        this.estado(jugadorObjetivo);
    }

    this.tirarFlecha = function(jugadorObjetivo){
        if(jugadorObjetivo.hp > 40){
            jugadorObjetivo.hp -= 40;
            this.estado(jugadorObjetivo);        
        }else{
            jugadorObjetivo.hp = 0;
            this.estado(jugadorObjetivo);        
            console.error(jugadorObjetivo.nombre + " " + "Esta muerto");
        }
        
    }

    this.estado = function(jugadorObjetivo){
        console.info(this);
        console.info(jugadorObjetivo);
    }
};


var gandalf = new Jugador("Gandalf");
var legolas = new Jugador("Legolas");

gandalf.curar(legolas);

console.log(gandalf)
console.log(legolas)