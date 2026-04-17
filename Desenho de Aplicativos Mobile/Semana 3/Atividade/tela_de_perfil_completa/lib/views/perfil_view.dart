import 'package:flutter/material.dart';

class PerfilView extends StatelessWidget {
  const PerfilView({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor:Color.fromARGB(255, 53, 8, 33) ,
      body: Column(
        children: [
          Stack(
            alignment: Alignment.bottomCenter,
            clipBehavior: Clip.none,
            children: [
              Image.network('https://images.unsplash.com/photo-1550751827-4bd374c3f58b?auto=format&fit=crop&w=800&q=80', height: 200, width: double.infinity, fit: BoxFit.cover),
              Positioned(bottom: -50, child: CircleAvatar(radius: 50, backgroundImage: NetworkImage('https://br.freepik.com/psd-gratuitas/ilustracao-3d-de-avatar-ou-perfil-humano_58509057.htm#fromView=keyword&page=1&position=7&uuid=4ca6d384-40ac-4300-ac92-6c7a59081e4c&query=Avatar+login'))),
            ]
          ),
          SizedBox(height: 60),
          Text('André Barbosa',
          style: TextStyle(
            fontFamily: 'monospace',
            color: Color.fromARGB(255, 14, 156, 14),
            fontSize: 24,
            fontWeight: FontWeight.bold),
            ),
          SizedBox(height: 8),
          
          Padding(
            padding: const EdgeInsets.all(16.0),
            child: Text('| Dev. Mobile | Flutter | Dart |',
            style: TextStyle(
              fontFamily: 'monospace',
              fontSize: 16,
              color: Color.fromARGB(255, 26, 216, 26),
              backgroundColor: Colors.black87)
              ),
          ),
          
          SizedBox(height: 24),
          Padding(padding: EdgeInsets.all(16),
            child: Row(mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Expanded(
                  child: ElevatedButton(onPressed:() {}, child: Text('Seguir'))
                ),

                SizedBox(width: 16),

                Expanded(
                  child: OutlinedButton(onPressed:() {}, child: Text('Home'))
                ),
              ],)
          ),
        ]
      )
    );
  }
}