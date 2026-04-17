import 'package:flutter/material.dart';

class ContadorView extends StatefulWidget {
  const ContadorView({super.key});

  @override
  State<ContadorView> createState() => _ContadorViewState();
}

class _ContadorViewState extends State<ContadorView> {
  int _contador = 0;

  void incrementar(){
    setState(() {
      _contador ++;
    });
  }

  void decrementar(){
    if(_contador > 0){
      setState(() {
        _contador --;
      });
    }
  }
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Contador Avançado')),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text('$_contador', style: const TextStyle(fontSize: 48)),

            if(_contador == 10)
              const Text('Meta Atingida',
              style: TextStyle(
                color: Colors.greenAccent,
                fontSize: 24,
                fontWeight: FontWeight.bold,
              )),

              const SizedBox(height: 20),

              Row(mainAxisAlignment: MainAxisAlignment.center,
              children: [
                ElevatedButton(onPressed: decrementar, child: const Text('-')),

                const SizedBox(width: 20),

                ElevatedButton(onPressed: incrementar, child: const Text('+'))
              ],
              )
          ],
        ),
      ),
    );
  }
}