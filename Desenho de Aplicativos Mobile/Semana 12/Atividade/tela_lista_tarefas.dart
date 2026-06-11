// 1. TELA PRINCIPAL: EXIBIÇÃO E PERSISTÊNCIA
import 'package:flutter/material.dart';
import 'package:pratica_semana_12/view/tela_cadastro.dart';
import 'package:shared_preferences/shared_preferences.dart';

class TelaListaTarefas extends StatefulWidget {
  const TelaListaTarefas({super.key});

  @override
  State<TelaListaTarefas> createState() => _TelaListaTarefasState();
}

class _TelaListaTarefasState extends State<TelaListaTarefas> {
  List<String> _tarefas = [];

  @override
  void initState() {
    super.initState();
    _carregarTarefas(); // Recupera os dados ao iniciar o widget [1, 4]
  }

  // Lógica para carregar dados do disco local
  Future<void> _carregarTarefas() async {
    final prefs = await SharedPreferences.getInstance();
    setState(() {
      // Recupera a lista salva ou inicia vazia se for a primeira vez
      _tarefas = prefs.getStringList('minhas_tarefas') ?? [];
    });
  }

  // Lógica para salvar a lista permanentemente no dispositivo [1]
  Future<void> _salvarNoDisco() async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.setStringList('minhas_tarefas', _tarefas);
  }

  // Navegação para a tela de cadastro aguardando retorno [5, 6]
  Future<void> _navegarParaCadastro(BuildContext context) async {
    final novaTarefa = await Navigator.push(
      context,
      MaterialPageRoute(builder: (context) => const TelaCadastro()),
    );

    if (novaTarefa != null && novaTarefa is String && novaTarefa.isNotEmpty) {
      setState(() {
        _tarefas.add(novaTarefa);
      });
      _salvarNoDisco(); // Persiste a mudança logo após atualizar o estado [1]
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Projeto Integrador - Semana 12'),
        backgroundColor: Colors.teal,
      ),
      body: _tarefas.isEmpty
          ? const Center(child: Text('Nenhuma tarefa pendente.'))
          : ListView.builder(
              itemCount: _tarefas.length,
              itemBuilder: (context, index) {
                return ListTile(
                  // ACESSIBILIDADE: Uso de Semantics para leitores de tela [7, 8]
                  leading: Semantics(
                    label: 'Ícone de tarefa pendente',
                    child: Icon(Icons.check_circle_outline),
                  ),
                  title: Text(_tarefas[index]),
                  trailing: IconButton(
                    icon: const Icon(Icons.delete, color: Colors.red),
                    onPressed: () {
                      setState(() {
                        _tarefas.removeAt(index);
                      });
                      _salvarNoDisco();
                    },
                  ),
                );
              },
            ),
      floatingActionButton: FloatingActionButton(
        onPressed: () => _navegarParaCadastro(context),
        child: const Icon(Icons.add),
      ),
    );
  }
}
