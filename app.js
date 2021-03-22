function Jugador(nombre){
    this.nombre = nombre;
    this.hp = 100;
    this.sp = 100;

    this.curar = function(jugadorObjetivo){
        jugadorObjetivo.hp += 20;

    }
};


var gandalf = new Jugador("Gandalg");
var legolas = new Jugador("Legolas");

gandalf.curar(legolas);

console.log(gandalf)
console.log(legolas)